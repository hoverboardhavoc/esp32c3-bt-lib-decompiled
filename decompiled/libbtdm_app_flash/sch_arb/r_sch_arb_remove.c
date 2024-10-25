/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_sch_arb_remove(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (param_1 != 0) {
    if (_r_co_list_extract_after == param_1) {
      _r_co_list_extract_after = 0;
    }
    else if (param_2 == 0) {
      if (param_1 == _sch_arb_env) {
        r_co_list_pop_front(&sch_arb_env);
        r_sch_arb_prog_timer();
      }
      else {
        iVar2 = r_co_list_extract(&sch_arb_env,param_1);
        if ((iVar2 == 0) && (iVar2 = r_co_list_extract(&sch_arb_env,param_1), iVar2 == 0)) {
          uVar1 = 2;
          goto _L121;
        }
      }
    }
  }
  uVar1 = 0;
_L121:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

