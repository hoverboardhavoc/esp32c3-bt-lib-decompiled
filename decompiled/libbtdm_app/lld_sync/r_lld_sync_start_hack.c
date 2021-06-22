/*
 * Last changed at upstream commit 4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * Upstream date: 2021-06-22 22:28:01 +0800
 * Upstream subject: Update ESP32-C3/ESP32-S3 bt-lib (e6e17bb4)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_start_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_sync_start_hack(uint param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = r_lld_sync_start();
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&lld_sync_env + param_1 * 4) != 0)) {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar3 + param_1 * 0x5a);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(param_1 * 0x5a + iVar3) = uVar1 & 0xffdf;
  }
  return uVar2;
}

