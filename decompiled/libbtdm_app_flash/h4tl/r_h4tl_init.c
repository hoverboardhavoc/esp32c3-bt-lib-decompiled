/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> h4tl.o -> r_h4tl_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_h4tl_init(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  
  iVar2 = param_1 * 0x28;
  piVar1 = (int *)(&h4tl_env + iVar2);
  (&DAT_00011022)[iVar2] = (char)param_1;
  r_ke_malloc[iVar2] = (code)0xff;
  (&DAT_0001102e)[iVar2] = 0xff;
  pcVar3 = *(code **)(param_2 + 8);
  *piVar1 = param_2;
  *(undefined4 *)(r_hci_send_2_host + iVar2) = 0;
  (*pcVar3)(pcVar3);
  r_ke_event_callback_set(8,r_h4tl_tx_evt_handler);
  r_ke_event_callback_set(9,r_h4tl_cmd_hdr_rx_evt_handler);
  r_ke_event_callback_set(10,r_h4tl_cmd_pld_rx_evt_handler);
  r_ke_event_callback_set(0xb,r_h4tl_acl_hdr_rx_evt_handler);
  r_ke_msg_alloc[iVar2] = (code)0x0;
  (**(code **)*piVar1)(iVar2 + 0x1101f,1,r_h4tl_rx_done,piVar1,*(code **)*piVar1);
  r_rwip_prevent_sleep_clear(4);
  return;
}

