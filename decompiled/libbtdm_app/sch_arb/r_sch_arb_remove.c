/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_arb.o -> r_sch_arb_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_sch_arb_remove(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (param_1 != 0) {
    if (_rwip_prog_delay == param_1) {
      _rwip_prog_delay = 0;
    }
    else if (param_2 == 0) {
      if (param_1 == _sch_arb_env) {
        (**(code **)(_r_modules_funcs_p + 0x40))(&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x40))
        ;
        (**(code **)(_r_ip_funcs_p + 0x6b4))(*(code **)(_r_ip_funcs_p + 0x6b4));
      }
      else {
        iVar1 = (**(code **)(_r_modules_funcs_p + 0x1c))
                          (&sch_arb_env,param_1,*(code **)(_r_modules_funcs_p + 0x1c));
        if (iVar1 == 0) {
          uVar2 = (**(code **)(_r_modules_funcs_p + 0x1c))
                            (&sch_arb_env,param_1,*(code **)(_r_modules_funcs_p + 0x1c));
          iVar1 = ((uVar2 ^ 1) & 0x7f) << 1;
          goto _L134;
        }
      }
    }
  }
  iVar1 = 0;
_L134:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return iVar1;
}

