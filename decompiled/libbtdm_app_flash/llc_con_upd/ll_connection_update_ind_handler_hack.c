/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> ll_connection_update_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_connection_update_ind_handler_hack(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = (uint)*(ushort *)(param_2 + 4);
  iVar1 = r_llc_con_upd_param_in_range
                    (uVar4,uVar4,*(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8));
  if (iVar1 == 0) {
    return 0x20;
  }
  if (uVar4 < *(ushort *)(param_2 + 2)) {
    return 0x20;
  }
  if (*(byte *)(param_2 + 1) == 0) {
    return 0x20;
  }
  iVar1 = 8;
  if (uVar4 < 10) {
    iVar1 = uVar4 - 1;
  }
  if (iVar1 < (int)(uint)*(byte *)(param_2 + 1)) {
    return 0x20;
  }
  if ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) {
    if ((param_3 - (uint)*(ushort *)(param_2 + 10) & 0xffff) < 0x7fff) {
      iVar1 = r_sdk_config_get_opts_ext(0x20);
      if ((*(byte *)(iVar1 + 0x1d) & 1) != 0) {
        return 0x28;
      }
      if (2 < _g_bt_plf_log_level) {
        ets_printf("con_upd: %u %u %u\n",param_1,param_3,*(undefined2 *)(param_2 + 10));
      }
    }
    iVar1 = r_llc_proc_id_get(param_1,0);
    if (iVar1 == 5) {
      iVar1 = r_llc_proc_get(param_1,0);
      *(undefined2 *)(iVar1 + 0x28) = *(undefined2 *)(param_2 + 4);
      *(undefined2 *)(iVar1 + 0xc) = *(undefined2 *)(param_2 + 6);
      *(undefined2 *)(iVar1 + 0xe) = *(undefined2 *)(param_2 + 8);
      *(undefined2 *)(iVar1 + 0x24) = *(undefined2 *)(param_2 + 10);
      *(undefined2 *)(iVar1 + 0x22) = *(undefined2 *)(param_2 + 2);
      *(undefined1 *)(iVar1 + 0x26) = *(undefined1 *)(param_2 + 1);
      r_llc_loc_con_upd_proc_continue(param_1,3,0);
    }
    else {
      iVar1 = r_llc_proc_id_get(param_1,1);
      uVar2 = 9;
      if (iVar1 == 0) {
        puVar3 = (undefined4 *)r_ke_msg_alloc(0x10b,1,0x30);
        *puVar3 = r_llc_rem_con_upd_proc_err_cb;
        *(undefined1 *)(puVar3 + 1) = 5;
        *(undefined1 *)((int)puVar3 + 0x2d) = 0;
        *(undefined1 *)((int)puVar3 + 0x2e) = 0;
        *(undefined2 *)((int)puVar3 + 0x16) = 0xffff;
        r_llc_proc_reg(param_1,1,puVar3);
        uVar2 = 7;
      }
      iVar1 = r_llc_proc_id_get(param_1,1);
      if (iVar1 != 5) goto _L202;
      iVar1 = r_llc_proc_get(param_1,1);
      r_llc_proc_state_set(param_1,uVar2);
      *(undefined2 *)(iVar1 + 0x28) = *(undefined2 *)(param_2 + 4);
      *(undefined2 *)(iVar1 + 0xc) = *(undefined2 *)(param_2 + 6);
      *(undefined2 *)(iVar1 + 0xe) = *(undefined2 *)(param_2 + 8);
      *(undefined2 *)(iVar1 + 0x24) = *(undefined2 *)(param_2 + 10);
      *(undefined2 *)(iVar1 + 0x22) = *(undefined2 *)(param_2 + 2);
      *(undefined1 *)(iVar1 + 0x26) = *(undefined1 *)(param_2 + 1);
      *(undefined1 *)(iVar1 + 0x2c) = 1;
      r_llc_rem_con_upd_proc_continue(param_1,uVar2,0);
    }
    uVar2 = 0;
  }
  else {
_L202:
    uVar2 = 0x24;
  }
  return uVar2;
}

