/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    iVar4 = *(int *)(iVar3 + 4) - (uint)rwip_prog_delay;
    if ((((1 - uVar1) + iVar4 & 0xfffffff) < 0x7ffffff) &&
       (((iVar4 + 1U & 0xfffffff) != uVar1 || (extraout_a1 <= *(uint *)(iVar3 + 8))))) {
      goto _L12;
    }
    uVar2 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x40));
    (**(code **)(_r_modules_funcs_p + 0x44))
              (&sch_arb_env,uVar2,*(code **)(_r_modules_funcs_p + 0x44));
    iVar3 = _sch_arb_env;
  }
  goto _L9;
  while( true ) {
    _r_ip_funcs_p =
         (**(code **)(_r_modules_funcs_p + 0x40))
                   (&sch_arb_env,*(code **)(_r_modules_funcs_p + 0x40));
    if (*(code **)(_r_ip_funcs_p + 0x18) != (code *)0x0) {
      (**(code **)(_r_ip_funcs_p + 0x18))();
    }
    iVar3 = ble_evt_kick_delay_get();
    if (iVar3 != 0) {
      ble_evt_kick_delay_update(0);
      (**(code **)(_r_ip_funcs_p + 0x6d0))(0xff,*(code **)(_r_ip_funcs_p + 0x6d0));
    }
    iVar3 = _sch_arb_env;
    if (_sch_arb_env == 0) break;
_L12:
    iVar4 = *(int *)(iVar3 + 4) - (uint)rwip_prog_delay;
    if (((~uVar1 + iVar4 & 0xfffffff) < 0x7ffffff) &&
       (((iVar4 - 1U & 0xfffffff) != uVar1 || (extraout_a1 < *(uint *)(iVar3 + 8))))) break;
  }
_L9:
  if (_ble_evt_kick_delay_get != 0) {
    (**(code **)(_r_modules_funcs_p + 0x2c0))(*(code **)(_r_modules_funcs_p + 0x2c0));
  }
                    /* WARNING: Could not recover jumptable at 0x0001007a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x6b4))();
  return;
}

