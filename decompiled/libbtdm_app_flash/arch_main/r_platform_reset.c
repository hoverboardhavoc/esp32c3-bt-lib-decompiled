/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> arch_main.o -> r_platform_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_platform_reset(int param_1)

{
  int iVar1;
  
  iVar1 = r_sdk_config_get_opts();
  if (*(char *)(iVar1 + 0x17) == '\0') {
    (**(code **)(_r_h4tl_eif_p + 0x14))(*(code **)(_r_h4tl_eif_p + 0x14));
  }
  *_unloaded_area = param_1;
  if ((param_1 != -0x3c3c3c3d) && (param_1 != -0x5a5a5a5b)) {
    (*(code *)0x0)();
    return;
  }
  return;
}

