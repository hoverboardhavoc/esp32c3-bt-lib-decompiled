/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
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
          goto _L131;
        }
      }
    }
  }
  uVar1 = 0;
_L131:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar2 + 0x28) & 1) != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar2 + 0x2c) < 2) {
      r_ble_log_internal_x2(0x20040005,param_1,uVar1);
    }
  }
  return uVar1;
}

