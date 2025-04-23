/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc.o -> r_llc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_init(int param_1)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  
  puVar2 = (undefined2 *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
  iVar3 = _r_plf_funcs_p;
  if (param_1 == 1) {
    memset(&llc_env,0,0x28);
    *puVar2 = 0;
    puVar2[1] = 0;
  }
  else if (param_1 == 2) {
    *puVar2 = 0;
    puVar2[1] = 0;
    iVar3 = (**(code **)(iVar3 + 0x38))(*(code **)(iVar3 + 0x38));
    for (uVar1 = (int)((*(byte *)(iVar3 + 0xd) - 1) * 0x1000000) >> 0x18; -1 < (char)uVar1;
        uVar1 = uVar1 - 1) {
      if (*(int *)(&llc_env + uVar1 * 4) != 0) {
        (**(code **)(_r_ip_funcs_p + 0x65c))(uVar1 & 0xff,1,*(code **)(_r_ip_funcs_p + 0x65c));
      }
    }
  }
  else if (param_1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001004c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x164))(&TASK_DESC_LLC,*(code **)(_r_modules_funcs_p + 0x164))
    ;
    return;
  }
  return;
}

