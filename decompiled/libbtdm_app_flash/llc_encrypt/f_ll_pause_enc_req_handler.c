/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> f_ll_pause_enc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_ll_pause_enc_req_handler(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) &&
     (iVar1 = r_llc_proc_id_get(1), iVar1 == 0)) {
    puVar2 = (undefined4 *)r_ke_msg_alloc(0x109,1,1,0x3c);
    *(undefined1 *)(puVar2 + 1) = 3;
    r_llc_proc_state_set(param_1,10);
    *puVar2 = r_llc_rem_encrypt_proc_err_cb;
    *(undefined1 *)((int)puVar2 + 0x3a) = 1;
    r_llc_proc_reg(param_1,1,puVar2);
    r_llc_rem_encrypt_proc_continue_eco(param_1,10,0);
    uVar3 = 0;
  }
  else {
    uVar3 = 0x24;
  }
  return uVar3;
}

