/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_h4tl_init(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  
  iVar1 = param_1 * 0x28;
  piVar2 = (int *)(&h4tl_env + iVar1);
  r_hci_cmd_get_max_param_size[iVar1] = (code)0xff;
  (&DAT_0001102a)[iVar1] = 0xff;
  pcVar3 = *(code **)(param_2 + 8);
  *piVar2 = param_2;
  (&DAT_0001101e)[iVar1] = (char)param_1;
  *(undefined4 *)(r_ke_msg_alloc + iVar1) = 0;
  (*pcVar3)(pcVar3);
  r_ke_event_callback_set(8,r_h4tl_tx_evt_handler);
  r_ke_event_callback_set(9,r_h4tl_cmd_hdr_rx_evt_handler);
  r_ke_event_callback_set(10,r_h4tl_cmd_pld_rx_evt_handler);
  r_ke_event_callback_set(0xb,r_h4tl_acl_hdr_rx_evt_handler);
  r_rwip_prevent_sleep_set[iVar1] = (code)0x0;
  (**(code **)*piVar2)(iVar1 + 0x1101b,1,r_h4tl_rx_done,piVar2,*(code **)*piVar2);
  r_rwip_prevent_sleep_clear(4);
  return;
}

