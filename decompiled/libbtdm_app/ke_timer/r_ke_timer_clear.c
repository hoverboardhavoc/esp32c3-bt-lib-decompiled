/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ke_timer.o -> r_ke_timer_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_timer_clear(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = _DAT_00011014;
  if (_DAT_00011014 == 0) {
    return;
  }
  if ((*(ushort *)(_DAT_00011014 + 4) == param_1) && (*(ushort *)(_DAT_00011014 + 6) == param_2)) {
    (**(code **)(_r_modules_funcs_p + 0x40))(&ke_env,*(code **)(_r_modules_funcs_p + 0x40));
    iVar2 = _DAT_00011014;
    uVar1 = 0xffffffff;
    if (_DAT_00011014 != 0) {
      uVar1 = *(undefined4 *)(_DAT_00011014 + 8);
    }
    (**(code **)(_r_modules_funcs_p + 0x2cc))(uVar1,*(code **)(_r_modules_funcs_p + 0x2cc));
    if ((iVar2 != 0) &&
       (iVar2 = (**(code **)(_r_modules_funcs_p + 0xac))
                          (*(undefined4 *)(iVar2 + 8),*(code **)(_r_modules_funcs_p + 0xac)),
       iVar2 != 0)) {
      (**(code **)(_r_modules_funcs_p + 0x108))(4,*(code **)(_r_modules_funcs_p + 0x108));
    }
  }
  else {
    iVar3 = (**(code **)(_r_modules_funcs_p + 0x158))
                      (&ke_env,*(undefined4 *)(_r_modules_funcs_p + 0xa0),param_1 << 0x10 | param_2,
                       *(code **)(_r_modules_funcs_p + 0x158));
    if (iVar3 == 0) {
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010304. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x110))(iVar3,*(code **)(_r_modules_funcs_p + 0x110));
  return;
}

