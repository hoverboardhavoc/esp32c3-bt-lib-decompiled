/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> ll_phy_update_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte ll_phy_update_ind_handler_hack(undefined4 param_1,int param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x18) == '\0') {
    return 0x24;
  }
  bVar1 = 0x20;
  if (((((*(byte *)(param_2 + 1) & 0xf8) == 0) && ((*(byte *)(param_2 + 2) & 0xf8) == 0)) &&
      (bVar1 = *(byte *)(param_2 + 1) | *(byte *)(param_2 + 2), bVar1 != 0)) &&
     (bVar1 = 0, (param_3 - *(ushort *)(param_2 + 4) & 0xffff) < 0x7fff)) {
    iVar2 = r_sdk_config_get_opts_ext();
    bVar1 = *(byte *)(iVar2 + 0x1d) & 4;
    if ((*(byte *)(iVar2 + 0x1d) & 4) == 0) {
      if (2 < _g_bt_plf_log_level) {
        ets_printf("phy_upd: %u %u %u\n",param_1,param_3,*(undefined2 *)(param_2 + 4));
      }
    }
    else {
      bVar1 = 0x28;
    }
    r_ble_log_internal_x2(0x804f0044,(uint)*(ushort *)(param_2 + 4) << 0x10 | param_3,param_1);
  }
  iVar2 = r_llc_proc_id_get(param_1,0);
  if (iVar2 == 9) {
    iVar2 = r_llc_proc_get(param_1,0);
    *(undefined1 *)(iVar2 + 0xc) = *(undefined1 *)(param_2 + 1);
    *(undefined1 *)(iVar2 + 0xd) = *(undefined1 *)(param_2 + 2);
    *(undefined2 *)(iVar2 + 8) = *(undefined2 *)(param_2 + 4);
    r_llc_loc_phy_upd_proc_continue_hack(param_1,3,bVar1);
  }
  else {
    iVar2 = r_llc_proc_id_get(param_1,1);
    if (iVar2 == 9) {
      iVar2 = r_llc_proc_get(param_1,1);
      *(undefined1 *)(iVar2 + 0xc) = *(undefined1 *)(param_2 + 1);
      *(undefined1 *)(iVar2 + 0xd) = *(undefined1 *)(param_2 + 2);
      *(undefined2 *)(iVar2 + 8) = *(undefined2 *)(param_2 + 4);
      r_llc_rem_phy_upd_proc_continue_eco(param_1,6,bVar1);
    }
    else {
      bVar1 = 0x24;
    }
  }
  return bVar1;
}

