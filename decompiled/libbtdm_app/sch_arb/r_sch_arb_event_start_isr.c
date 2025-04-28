/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint extraout_a1;
  int iVar4;
  
  iVar3 = _sch_arb_env;
  uVar1 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  while (iVar3 != 0) {
    iVar4 = *(int *)(iVar3 + 4) - (_rwip_prog_delay & 0xff);
    if ((((1 - uVar1) + iVar4 & 0xfffffff) < 0x7ffffff) &&
       (((iVar4 + 1U & 0xfffffff) != uVar1 || (extraout_a1 <= *(uint *)(iVar3 + 8))))) goto _L16;
    uVar2 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x40));
    (**(code **)(_r_modules_funcs_p + 0x44))
              (&sch_arb_env,uVar2,*(code **)(_r_modules_funcs_p + 0x44));
    iVar3 = _sch_arb_env;
  }
  goto _L9;
  while( true ) {
    _rwip_prog_delay =
         (**(code **)(_r_modules_funcs_p + 0x40))
                   (&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x40));
    if (*(code **)(_rwip_prog_delay + 0x18) != (code *)0x0) {
      (**(code **)(_rwip_prog_delay + 0x18))();
    }
    iVar3 = ble_evt_kick_delay_get();
    if (iVar3 != 0) {
      ble_evt_kick_delay_update(0);
      (**(code **)(_r_ip_funcs_p + 0x6d0))(0xff,*(code **)(_r_ip_funcs_p + 0x6d0));
    }
    iVar3 = _sch_arb_env;
    if (_sch_arb_env == 0) break;
_L16:
    iVar4 = *(int *)(iVar3 + 4) - (_rwip_prog_delay & 0xff);
    if ((((iVar4 - uVar1) - 1 & 0xfffffff) < 0x7ffffff) &&
       (((iVar4 - 1U & 0xfffffff) != uVar1 || (extraout_a1 < *(uint *)(iVar3 + 8))))) break;
  }
_L9:
  if (_r_ip_funcs_p != 0) {
    (**(code **)(_r_modules_funcs_p + 0x2c0))(*(code **)(_r_modules_funcs_p + 0x2c0));
  }
                    /* WARNING: Could not recover jumptable at 0x00010084. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x6b4))(*(code **)(_r_ip_funcs_p + 0x6b4));
  return;
}

