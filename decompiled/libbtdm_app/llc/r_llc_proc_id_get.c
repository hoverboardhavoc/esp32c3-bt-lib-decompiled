/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc.o -> r_llc_proc_id_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_llc_proc_id_get(int param_1,uint param_2)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    (**(code **)(_r_plf_funcs_p + 0xc))("llc.c",0x1f2,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar1 = *(int *)(param_2 * 4 + iVar1);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined1 *)(iVar1 + 4);
  }
  return uVar2;
}

