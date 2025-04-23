/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_tx_done(void)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  undefined1 uVar6;
  
  iVar4 = _r_ke_msg_free;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  r_hci_ble_adv_report_tx_check(iVar4);
  r_assert_err = (code)0x1;
  uVar1 = *(ushort *)(iVar4 + 4);
  if (uVar1 < 0x1106) {
    if (uVar1 < 0x1101) {
_L134:
      r_assert_param(0,"hci_tl.c",0x51f);
    }
  }
  else {
    if (uVar1 != 0x1106) goto _L134;
    r_co_list_pop_front(&hci_tl_env);
    uVar1 = *(ushort *)(iVar4 + 0xc);
    pbVar3 = (byte *)r_sdk_config_get_hl_derived_opts();
    if ((uVar1 & 0xfff) < (ushort)*pbVar3) {
      r_ble_util_buf_rx_free(*(undefined2 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0x14));
    }
    _r_ke_msg_free = 0;
    r_hci_fc_acl_packet_sent();
  }
  if (_r_ke_msg_free != 0) {
    iVar4 = r_co_list_pop_front(&hci_tl_env);
  }
  r_ke_msg_free(iVar4);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  iVar4 = _hci_tl_env;
  if (_hci_tl_env == 0) {
    iVar4 = r_hci_fc_check_host_available_nb_acl_packets();
    if (iVar4 == 0) {
      DAT_0001101e = 1;
      return;
    }
    DAT_0001101e = 0;
    iVar4 = _r_co_list_init;
    if (_r_co_list_init == 0) {
      DAT_0001101e = 0;
      return;
    }
  }
  _r_ke_msg_free = iVar4;
  switch(*(short *)(iVar4 + 4) + -0x1101) {
  case 0:
    if (((*(short *)(iVar4 + 8) != 0xc03) && (*(short *)(iVar4 + 8) != 0xc35)) &&
       (iVar2 = (DAT_0001101d + 1) * 0x1000000, DAT_0001101d = (byte)((uint)iVar2 >> 0x18),
       5 < iVar2 >> 0x18)) {
      r_assert_err(0,"hci_tl.c",0x428);
    }
    iVar4 = r_hci_build_cc_evt(iVar4);
    break;
  case 1:
    iVar2 = (DAT_0001101d + 1) * 0x1000000;
    DAT_0001101d = (byte)((uint)iVar2 >> 0x18);
    if (5 < iVar2 >> 0x18) {
      r_assert_err(0,"hci_tl.c",0x437);
    }
    iVar4 = r_hci_build_cs_evt(iVar4);
    break;
  case 2:
    iVar4 = r_hci_build_evt(iVar4);
    break;
  case 3:
    iVar4 = r_hci_build_le_evt(iVar4);
    break;
  default:
    r_assert_param(0,"hci_tl.c",0x4a0);
    uVar6 = 0;
    uVar5 = 0;
    iVar4 = 0;
    goto _L126;
  case 5:
    iVar4 = r_hci_build_acl_data(iVar4);
    uVar5 = *(ushort *)(iVar4 + 2) + 4 & 0xffff;
    uVar6 = 2;
    goto _L126;
  }
  uVar6 = 4;
  uVar5 = *(byte *)(iVar4 + 1) + 2;
_L126:
  r_assert_err = (code)0x0;
  iVar2 = r_sdk_config_get_opts();
  if (*(char *)(iVar2 + 0x17) != '\x01') {
    r_h4tl_write(uVar6,iVar4,r_hci_tx_done);
    return;
  }
  *(undefined1 *)(iVar4 + -1) = uVar6;
  r_vhci_send_to_host(iVar4 + -1,uVar5 + 1);
  r_ke_event_set(5);
  return;
}

