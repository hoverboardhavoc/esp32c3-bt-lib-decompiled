/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llc_chmap_upd.o -> ll_channel_map_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte ll_channel_map_ind_handler_hack(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) &&
     (iVar2 = r_llc_proc_id_get(1), iVar2 == 0)) {
    uVar3 = r_co_nb_good_le_channels((void *)(param_2 + 1));
    bVar1 = 0x20;
    if (1 < uVar3) {
      bVar1 = *(byte *)(param_2 + 5) & 0xe0;
      if ((*(byte *)(param_2 + 5) & 0xe0) == 0) {
        if ((param_3 - *(ushort *)(param_2 + 6) & 0xffff) < 0x7fff) {
          iVar2 = r_sdk_config_get_opts_ext();
          if ((*(byte *)(iVar2 + 0x1d) & 2) != 0) {
            return 0x28;
          }
          if (2 < _g_bt_plf_log_level) {
            ets_printf("chm_upd: %u %u %u\n",param_1,param_3,*(undefined2 *)(param_2 + 6));
          }
          r_ble_log_internal_x2(0x804f0080,(uint)*(ushort *)(param_2 + 6) << 0x10 | param_3,param_1)
          ;
        }
        puVar4 = (undefined4 *)r_ke_msg_alloc(0x10d,param_1 << 8 | 1,0x10);
        *(undefined1 *)(puVar4 + 1) = 6;
        r_llc_proc_state_set(param_1,3);
        *puVar4 = r_llc_ch_map_up_proc_err_cb;
        memcpy(puVar4 + 2,(void *)(param_2 + 1),5);
        *(undefined2 *)((int)puVar4 + 0xe) = *(undefined2 *)(param_2 + 6);
        r_llc_proc_reg(param_1,1,puVar4);
        r_llc_rem_ch_map_proc_continue(param_1,3,0);
      }
      else {
        bVar1 = 0x20;
      }
    }
  }
  else {
    bVar1 = 0x24;
  }
  return bVar1;
}

