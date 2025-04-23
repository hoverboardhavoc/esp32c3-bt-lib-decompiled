/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_arb.o -> r_sch_arb_event_start_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_arb_event_start_isr(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint extraout_a1;
  int iVar4;
  
  iVar1 = _sch_arb_env;
  uVar2 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  while ((iVar1 != 0 &&
         ((iVar4 = *(int *)(iVar1 + 4) - (_rwip_prog_delay & 0xff),
          0x7fffffe < ((1 - uVar2) + iVar4 & 0xfffffff) ||
          (((iVar4 + 1U & 0xfffffff) == uVar2 && (*(uint *)(iVar1 + 8) < extraout_a1))))))) {
    uVar3 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x40));
    (**(code **)(_r_modules_funcs_p + 0x44))
              (&sch_arb_env,uVar3,*(code **)(_r_modules_funcs_p + 0x44));
    iVar1 = _sch_arb_env;
  }
  while ((iVar1 != 0 &&
         ((iVar4 = *(int *)(iVar1 + 4) - (_rwip_prog_delay & 0xff),
          0x7fffffe < ((iVar4 - uVar2) - 1 & 0xfffffff) ||
          (((iVar4 - 1U & 0xfffffff) == uVar2 && (*(uint *)(iVar1 + 8) <= extraout_a1))))))) {
    _rwip_prog_delay =
         (**(code **)(_r_modules_funcs_p + 0x40))
                   (&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x40));
    if (*(code **)(_rwip_prog_delay + 0x18) != (code *)0x0) {
      (**(code **)(_rwip_prog_delay + 0x18))();
    }
    iVar4 = ble_evt_kick_delay_get();
    iVar1 = _sch_arb_env;
    if (iVar4 != 0) {
      ble_evt_kick_delay_update(0);
      (**(code **)(_r_ip_funcs_p + 0x6d0))(0xff,*(code **)(_r_ip_funcs_p + 0x6d0));
      iVar1 = _sch_arb_env;
    }
  }
  if (_r_ip_funcs_p != 0) {
    (**(code **)(_r_modules_funcs_p + 0x2c0))(*(code **)(_r_modules_funcs_p + 0x2c0));
  }
                    /* WARNING: Could not recover jumptable at 0x000100d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x6b4))(*(code **)(_r_ip_funcs_p + 0x6b4));
  return;
}

