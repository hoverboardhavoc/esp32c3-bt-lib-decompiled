/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_activity_syncing_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_llm_activity_syncing_get(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while ((iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
         uVar1 < *(byte *)(iVar2 + 0xd) &&
         (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) != '\x0e'))) {
    uVar1 = uVar1 + 1 & 0xff;
  }
  return uVar1;
}

