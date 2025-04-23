/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_timer.o -> r_ke_timer_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_timer_set(uint param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 1;
  if (param_3 != 0) {
    uVar4 = param_3;
  }
  if (0x3fffff < uVar4) {
    uVar4 = 0x3fffff;
  }
  bVar1 = false;
  if ((_DAT_00011014 != 0) && (*(ushort *)(_DAT_00011014 + 4) == param_1)) {
    bVar1 = *(ushort *)(_DAT_00011014 + 6) == param_2;
  }
  iVar2 = (**(code **)(_r_modules_funcs_p + 0x158))
                    (&ke_env,*(undefined4 *)(_r_modules_funcs_p + 0xa0),param_1 << 0x10 | param_2,
                     *(code **)(_r_modules_funcs_p + 0x158));
  if (iVar2 == 0) {
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x120))(0xc,2,*(code **)(_r_modules_funcs_p + 0x120));
    if (iVar2 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))("ke_timer.c",0xfa,*(code **)(_r_plf_funcs_p + 8));
    }
    *(short *)(iVar2 + 4) = (short)param_1;
    *(short *)(iVar2 + 6) = (short)param_2;
  }
  iVar3 = (**(code **)(_r_modules_funcs_p + 0xa4))(*(code **)(_r_modules_funcs_p + 0xa4));
  *(uint *)(iVar2 + 8) = uVar4 + iVar3 & 0x7fffff;
  (**(code **)(_r_modules_funcs_p + 0x15c))
            (&ke_env,iVar2,*(undefined4 *)(_r_modules_funcs_p + 0x9c),
             *(code **)(_r_modules_funcs_p + 0x15c));
  if ((bVar1) || (iVar2 == _DAT_00011014)) {
    (**(code **)(_r_modules_funcs_p + 0x2cc))
              (*(undefined4 *)(_DAT_00011014 + 8),*(code **)(_r_modules_funcs_p + 0x2cc));
  }
  iVar2 = (**(code **)(_r_modules_funcs_p + 0xac))
                    (uVar4 + iVar3,*(code **)(_r_modules_funcs_p + 0xac));
  if (iVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00010270. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x108))(4,*(code **)(_r_modules_funcs_p + 0x108));
    return;
  }
  return;
}

