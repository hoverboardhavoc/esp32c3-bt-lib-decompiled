/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> r_llc_ll_pause_enc_rsp_ack_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001034e) */
/* WARNING: Removing unreachable block (ram,0x00010354) */
/* WARNING: Removing unreachable block (ram,0x0001029e) */
/* WARNING: Removing unreachable block (ram,0x000102a4) */
/* WARNING: Removing unreachable block (ram,0x000102a8) */
/* WARNING: Removing unreachable block (ram,0x000102ae) */
/* WARNING: Removing unreachable block (ram,0x000102b0) */
/* WARNING: Removing unreachable block (ram,0x0001035a) */
/* WARNING: Removing unreachable block (ram,0x00010360) */
/* WARNING: Removing unreachable block (ram,0x00010592) */

void r_llc_ll_pause_enc_rsp_ack_handler(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = r_llc_proc_id_get(0);
  if (iVar2 != 3) {
    return;
  }
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = r_llc_proc_get(0);
  iVar1 = r_llc_proc_state_get();
  if (iVar1 == 2) {
    r_llc_iv_skd_rand_gen(param_1);
    r_llc_proc_state_set(iVar2,param_1,3);
    return;
  }
  r_llc_disconnect(param_1,0x3d,1);
  iVar1 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar1 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    *(byte *)(iVar3 + 0x45) = *(byte *)(iVar3 + 0x45) & 0xf7;
    r_lld_con_data_flow_set(param_1,1);
    r_llc_llcp_state_set(param_1,2,0);
    r_llc_proc_timer_pause_set(param_1,1,0);
    *(ushort *)(iVar3 + 0x42) = *(ushort *)(iVar3 + 0x42) & 0xffdf;
    r_llc_le_ping_restart(param_1);
  }
  r_llc_hci_enc_evt_send(param_1,0x3d,*(undefined1 *)(iVar2 + 0x3a));
  r_llc_proc_unreg(param_1,0);
  *(ushort *)(iVar3 + 0x42) = *(ushort *)(iVar3 + 0x42) & 0xfdff;
  return;
}

