/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_chmap_upd.o -> ll_channel_map_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_channel_map_ind_handler_hack(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) &&
     (iVar1 = r_llc_proc_id_get(1), iVar1 == 0)) {
    uVar2 = r_co_nb_good_le_channels((void *)(param_2 + 1));
    if ((uVar2 < 2) || ((*(byte *)(param_2 + 5) & 0xe0) != 0)) {
      uVar4 = 0x20;
    }
    else {
      if ((param_3 - (uint)*(ushort *)(param_2 + 6) & 0xffff) < 0x7fff) {
        iVar1 = r_sdk_config_get_opts_ext();
        if ((*(byte *)(iVar1 + 0x1d) & 2) != 0) {
          return 0x28;
        }
        if (2 < _g_bt_plf_log_level) {
          ets_printf("chm_upd: %u %u %u\n",param_1,param_3,*(undefined2 *)(param_2 + 6));
        }
      }
      puVar3 = (undefined4 *)r_ke_msg_alloc(0x10d,param_1 << 8 | 1,0x10);
      *(undefined1 *)(puVar3 + 1) = 6;
      r_llc_proc_state_set(param_1,3);
      *puVar3 = r_llc_ch_map_up_proc_err_cb;
      memcpy(puVar3 + 2,(void *)(param_2 + 1),5);
      *(undefined2 *)((int)puVar3 + 0xe) = *(undefined2 *)(param_2 + 6);
      r_llc_proc_reg(param_1,1,puVar3);
      r_llc_rem_ch_map_proc_continue(param_1,3,0);
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0x24;
  }
  return uVar4;
}

