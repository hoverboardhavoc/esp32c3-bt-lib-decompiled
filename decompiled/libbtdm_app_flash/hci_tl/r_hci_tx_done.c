/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  undefined1 uVar6;
  
  iVar3 = _r_ke_msg_free;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  r_hci_ble_adv_report_tx_check(iVar3);
  r_assert_err = (code)0x1;
  r_ble_log_internal_x1(0x20070198,*(ushort *)(iVar3 + 4) | 0x10000);
  uVar1 = *(ushort *)(iVar3 + 4);
  if (uVar1 < 0x1106) {
    if (uVar1 < 0x1101) {
_L127:
      r_assert_param(0,"hci_tl.c",0x520);
    }
  }
  else {
    if (uVar1 != 0x1106) goto _L127;
    r_co_list_pop_front(&hci_tl_env);
    uVar1 = *(ushort *)(iVar3 + 0xc);
    pbVar4 = (byte *)r_sdk_config_get_hl_derived_opts();
    if ((uVar1 & 0xfff) < (ushort)*pbVar4) {
      r_ble_util_buf_rx_free(*(undefined2 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x14));
    }
    _r_ke_msg_free = 0;
    r_hci_fc_acl_packet_sent();
  }
  if (_r_ke_msg_free != 0) {
    iVar3 = r_co_list_pop_front(&hci_tl_env);
  }
  r_ke_msg_free(iVar3);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  iVar3 = _hci_tl_env;
  if (_hci_tl_env == 0) {
    iVar3 = r_hci_fc_check_host_available_nb_acl_packets();
    if (iVar3 == 0) {
      DAT_0001201e = 1;
      return;
    }
    DAT_0001201e = 0;
    iVar3 = _r_co_list_init;
    if (_r_co_list_init == 0) {
      DAT_0001201e = 0;
      return;
    }
  }
  _r_ke_msg_free = iVar3;
  switch(*(short *)(iVar3 + 4) + -0x1101) {
  case 0:
    if (((*(short *)(iVar3 + 8) != 0xc03) && (*(short *)(iVar3 + 8) != 0xc35)) &&
       (iVar2 = (DAT_0001201d + 1) * 0x1000000, DAT_0001201d = (byte)((uint)iVar2 >> 0x18),
       5 < iVar2 >> 0x18)) {
      r_assert_err(0,"hci_tl.c",0x428);
    }
    iVar3 = r_hci_build_cc_evt(iVar3);
    break;
  case 1:
    iVar2 = (DAT_0001201d + 1) * 0x1000000;
    DAT_0001201d = (byte)((uint)iVar2 >> 0x18);
    if (5 < iVar2 >> 0x18) {
      r_assert_err(0,"hci_tl.c",0x437);
    }
    iVar3 = r_hci_build_cs_evt(iVar3);
    break;
  case 2:
    iVar3 = r_hci_build_evt(iVar3);
    break;
  case 3:
    iVar3 = r_hci_build_le_evt(iVar3);
    break;
  default:
    r_assert_param(0,"hci_tl.c",0x4a0);
    uVar6 = 0;
    uVar5 = 0;
    iVar3 = 0;
    goto _L119;
  case 5:
    iVar3 = r_hci_build_acl_data(iVar3);
    uVar5 = *(ushort *)(iVar3 + 2) + 4 & 0xffff;
    uVar6 = 2;
    goto _L119;
  }
  uVar6 = 4;
  uVar5 = *(byte *)(iVar3 + 1) + 2;
_L119:
  r_assert_err = (code)0x0;
  iVar2 = r_sdk_config_get_opts();
  if (*(char *)(iVar2 + 0x17) != '\x01') {
    r_h4tl_write(uVar6,iVar3,r_hci_tx_done);
    return;
  }
  *(undefined1 *)(iVar3 + -1) = uVar6;
  r_vhci_send_to_host(iVar3 + -1,uVar5 + 1);
  r_ke_event_set(5);
  return;
}

