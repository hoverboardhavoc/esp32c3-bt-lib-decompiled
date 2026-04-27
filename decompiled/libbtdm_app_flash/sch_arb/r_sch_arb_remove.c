/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_remove
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
    if (_r_co_list_extract_after == param_1) {
      _r_co_list_extract_after = 0;
    }
    else if (param_2 == 0) {
      if (param_1 == _sch_arb_env) {
        r_co_list_pop_front(&sch_arb_env);
        r_sch_arb_prog_timer();
        iVar1 = 0;
        goto _L121;
      }
      iVar1 = r_co_list_extract(&sch_arb_env,param_1);
      if (iVar1 == 0) {
        uVar2 = r_co_list_extract(&sch_arb_env,param_1);
        iVar1 = ((uVar2 ^ 1) & 0x7f) << 1;
        goto _L121;
      }
    }
  }
  iVar1 = 0;
_L121:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  r_ble_log_internal_x2(0x20090229,param_1,iVar1);
  return iVar1;
}

