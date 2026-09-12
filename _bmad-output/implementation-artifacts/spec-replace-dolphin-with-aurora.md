---
title: 'Replace extern/dolphin with extern/aurora'
type: 'refactor'
created: '2026-09-12'
status: 'draft'
route: 'dispatch'
review_loop_iteration: 0
context: []
---

<frozen-after-approval reason="human-owned intent — do not modify unless human renegotiates">

## Intent

**Problem:** The project is migrating to use `extern/aurora` as a drop-in replacement for the original Dolphin SDK in `extern/dolphin`.

**Approach:** Replace all references to `extern/dolphin` with `extern/aurora` in project configuration and build scripts, including `configure.py`, `Doxyfile`, `tools/m2ctx/m2ctx.py`, and `tools/replace-includes.py`.

## Boundaries & Constraints

**Always:** Ensure that path replacements correctly align with the folder structure of `extern/aurora` (e.g., `include` and `lib` instead of `include` and `src`).

**Never:** Leave dangling references to `extern/dolphin`.

</frozen-after-approval>

## Open Questions

- Should DolphinLib be removed from `configure.py`? — options: Remove DolphinLib (Since aurora doesn't contain the GameCube SDK C files like OS.c, we stop compiling these and rely on aurora's separate build or linking process) / Keep and modify (We need to compile specific aurora C++ files in configure.py, which will require listing the exact new files and changing the compiler logic to support C++ for DolphinLib).

## Code Map

- `configure.py` -- Contains the project build configuration, including `DolphinLib` which points to `extern/dolphin/src` and various `.c` files.
- `Doxyfile` -- Contains include paths for documentation generation.
- `tools/m2ctx/m2ctx.py` -- Contains include paths (`extern/dolphin/include`) for context generation.
- `tools/replace-includes.py` -- Contains include paths for `#include` generation.

## Tasks & Acceptance

**Execution:**
- [ ] `configure.py` -- Replace include paths from `extern/dolphin/include` to `extern/aurora/include`, and apply the chosen approach for `DolphinLib`.
- [ ] `Doxyfile` -- Replace `extern/dolphin` with `extern/aurora`.
- [ ] `tools/m2ctx/m2ctx.py` -- Replace `extern/dolphin/include` with `extern/aurora/include`.
- [ ] `tools/replace-includes.py` -- Replace `extern/dolphin/include` with `extern/aurora/include`.

**Acceptance Criteria:**
- Given the codebase, when searching for `extern/dolphin`, then no matches are found in tracked files.
- Given the build system, when configuring and building, then it successfully builds with `extern/aurora`.

## Implementation Notes


## Spec Change Log


## Review Triage Log
