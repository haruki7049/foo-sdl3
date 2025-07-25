{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    systems.url = "github:nix-systems/default";
    flake-compat.url = "github:edolstra/flake-compat";
    flake-parts = {
      url = "github:hercules-ci/flake-parts";
      inputs.nixpkgs-lib.follows = "nixpkgs";
    };
    treefmt-nix = {
      url = "github:numtide/treefmt-nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs =
    inputs:
    inputs.flake-parts.lib.mkFlake { inherit inputs; } {
      systems = import inputs.systems;

      imports = [
        inputs.treefmt-nix.flakeModule
      ];

      perSystem =
        {
          pkgs,
          lib,
          ...
        }:
        let
          src = lib.cleanSource ./.;
          nativeBuildInputs = [
            pkgs.scons
            pkgs.pkg-config
          ];
          buildInputs = [
            pkgs.sdl3
            pkgs.cunit
          ];
          env = {
            CFLAGS = "-std=c23";
          };

          foo-sdl3 = pkgs.stdenv.mkDerivation {
            name = "foo-sdl3";
            inherit src nativeBuildInputs buildInputs env;

            installPhase = ''
              mkdir -p $out/bin
              cp build/foo-sdl3 $out/bin/foo-sdl3
            '';
          };
        in
        {
          treefmt = {
            projectRootFile = "flake.nix";

            # Nix
            programs.nixfmt.enable = true;

            # C
            programs.clang-format.enable = true;

            # GitHub Actions
            programs.actionlint.enable = true;

            # Markdown
            programs.mdformat.enable = true;

            # ShellScript
            programs.shellcheck.enable = true;
            programs.shfmt.enable = true;
          };

          packages = {
            inherit foo-sdl3;
            default = foo-sdl3;
          };

          devShells.default = pkgs.mkShell {
            inherit nativeBuildInputs buildInputs env;

            shellHook = ''
              export PS1="\n[nix-shell:\w]$ "
            '';
          };
        };
    };
}
