/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
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
  while (iVar1 != 0) {
    iVar4 = *(int *)(iVar1 + 4) - (uint)rwip_prog_delay;
    if ((((1 - uVar2) + iVar4 & 0xfffffff) < 0x7ffffff) &&
       (((iVar4 + 1U & 0xfffffff) != uVar2 || (extraout_a1 <= *(uint *)(iVar1 + 8))))) {
      goto _L11;
    }
    uVar3 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x40));
    (**(code **)(_r_modules_funcs_p + 0x44))
              (&sch_arb_env,uVar3,*(code **)(_r_modules_funcs_p + 0x44));
    iVar1 = _sch_arb_env;
  }
  goto _L9;
  while( true ) {
    _r_ip_funcs_p =
         (**(code **)(_r_modules_funcs_p + 0x40))
                   (&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x40));
    if (*(code **)(_r_ip_funcs_p + 0x18) != (code *)0x0) {
      (**(code **)(_r_ip_funcs_p + 0x18))();
    }
    iVar1 = _sch_arb_env;
    if (_sch_arb_env == 0) break;
_L11:
    iVar4 = *(int *)(iVar1 + 4) - (uint)rwip_prog_delay;
    if (((~uVar2 + iVar4 & 0xfffffff) < 0x7ffffff) &&
       (((iVar4 - 1U & 0xfffffff) != uVar2 || (extraout_a1 < *(uint *)(iVar1 + 8))))) break;
  }
_L9:
  if (_DAT_00011010 != 0) {
    (**(code **)(_r_modules_funcs_p + 0x2c0))(*(code **)(_r_modules_funcs_p + 0x2c0));
  }
                    /* WARNING: Could not recover jumptable at 0x00010076. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x6b4))();
  return;
}

