/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> ll_enc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ll_enc_req_handler(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x20) == '\0') {
    return 0x24;
  }
  if ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) {
    iVar2 = r_llc_proc_id_get(1,param_3);
    uVar3 = 0xc;
    if (iVar2 == 0) {
      puVar1 = (undefined4 *)r_ke_msg_alloc(0x109,1,1,0x3c);
      *(undefined1 *)(puVar1 + 1) = 3;
      *puVar1 = r_llc_rem_encrypt_proc_err_cb;
      *(undefined1 *)((int)puVar1 + 0x3a) = 0;
      r_llc_proc_reg(param_1,1,puVar1);
      r_llc_proc_state_set(puVar1,param_1,10);
      uVar3 = 10;
    }
    iVar2 = r_llc_proc_id_get(param_1,1);
    if (iVar2 == 3) {
      iVar2 = r_llc_proc_get(param_1,1);
      *(undefined2 *)(iVar2 + 0x38) = *(undefined2 *)(param_2 + 10);
      memcpy((void *)(iVar2 + 0x20),(void *)(param_2 + 0x14),4);
      memcpy((void *)(iVar2 + 0x28),(void *)(param_2 + 0xc),8);
      memcpy((void *)(iVar2 + 8),(void *)(param_2 + 1),8);
      r_llc_rem_encrypt_proc_continue_eco(param_1,uVar3,0);
      return 0;
    }
  }
  else {
    iVar2 = r_llc_proc_id_get(0);
    if (iVar2 == 3) {
      r_llc_loc_encrypt_proc_continue(param_1,9,0x3d);
      return 0;
    }
  }
  return 0x24;
}

