/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_adv.o -> r_llm_adv_con_len_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_adv_con_len_check(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((*(ushort *)(param_1 + 2) & 0x10) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_adv.c",0xc0b,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((*(ushort *)(param_1 + 2) & 1) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_adv.c",0xc0c,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar2 = 6;
  if ((*(ushort *)(param_1 + 2) & 4) != 0) {
    iVar2 = 0xc;
  }
  iVar3 = iVar2 + 3;
  if ((*(ushort *)(param_1 + 2) & 0x40) == 0) {
    iVar3 = iVar2 + 2;
  }
  uVar1 = 0;
  if (0xfe < iVar3 + 1 + param_2) {
    uVar1 = 0x12;
  }
  return uVar1;
}

