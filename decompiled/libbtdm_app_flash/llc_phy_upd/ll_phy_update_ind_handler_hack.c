/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> ll_phy_update_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_phy_update_ind_handler_hack(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x18) == '\0') {
    return 0x24;
  }
  uVar2 = 0x20;
  if ((*(byte *)(param_2 + 1) < 8) && (*(byte *)(param_2 + 2) < 8)) {
    if ((*(byte *)(param_2 + 1) != 0 || *(byte *)(param_2 + 2) != 0) &&
       ((param_3 - (uint)*(ushort *)(param_2 + 4) & 0xffff) < 0x7fff)) {
      iVar1 = r_sdk_config_get_opts_ext();
      uVar2 = 0x28;
      if ((*(byte *)(iVar1 + 0x1d) & 4) != 0) goto _L211;
      if (2 < _g_bt_plf_log_level) {
        ets_printf("phy_upd: %u %u %u\n",param_1,param_3,*(undefined2 *)(param_2 + 4));
      }
    }
    uVar2 = 0;
  }
_L211:
  iVar1 = r_llc_proc_id_get(param_1,0);
  if (iVar1 == 9) {
    iVar1 = r_llc_proc_get(param_1,0);
    *(undefined1 *)(iVar1 + 0xc) = *(undefined1 *)(param_2 + 1);
    *(undefined1 *)(iVar1 + 0xd) = *(undefined1 *)(param_2 + 2);
    *(undefined2 *)(iVar1 + 8) = *(undefined2 *)(param_2 + 4);
    r_llc_loc_phy_upd_proc_continue(param_1,3,uVar2);
  }
  else {
    iVar1 = r_llc_proc_id_get(param_1,1);
    if (iVar1 == 9) {
      iVar1 = r_llc_proc_get(param_1,1);
      *(undefined1 *)(iVar1 + 0xc) = *(undefined1 *)(param_2 + 1);
      *(undefined1 *)(iVar1 + 0xd) = *(undefined1 *)(param_2 + 2);
      *(undefined2 *)(iVar1 + 8) = *(undefined2 *)(param_2 + 4);
      r_llc_rem_phy_upd_proc_continue_eco(param_1,6,uVar2);
    }
    else {
      uVar2 = 0x24;
    }
  }
  return uVar2;
}

