/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_tx_trigger
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_tx_trigger(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  
  if ((_hci_tl_env & 0xff) != 1) {
    return;
  }
  uVar3 = _hci_tl_env;
  if (_hci_tl_env == 0) {
    iVar1 = r_hci_fc_check_host_available_nb_acl_packets();
    if (iVar1 == 0) {
      DAT_0001101e = 1;
      return;
    }
    DAT_0001101e = 0;
    uVar3 = _r_co_list_init;
    if (_r_co_list_init == 0) {
      DAT_0001101e = 0;
      return;
    }
  }
  _r_ke_msg_free = uVar3;
  switch(*(short *)(uVar3 + 4) + -0x1101) {
  case 0:
    if (((*(short *)(uVar3 + 8) != 0xc03) && (*(short *)(uVar3 + 8) != 0xc35)) &&
       (iVar1 = (DAT_0001101d + 1) * 0x1000000, DAT_0001101d = (byte)((uint)iVar1 >> 0x18),
       5 < iVar1 >> 0x18)) {
      r_assert_err(0,"hci_tl.c",0x428);
    }
    iVar1 = r_hci_build_cc_evt(uVar3);
    break;
  case 1:
    iVar1 = (DAT_0001101d + 1) * 0x1000000;
    DAT_0001101d = (byte)((uint)iVar1 >> 0x18);
    if (5 < iVar1 >> 0x18) {
      r_assert_err(0,"hci_tl.c",0x437);
    }
    iVar1 = r_hci_build_cs_evt(uVar3);
    break;
  case 2:
    iVar1 = r_hci_build_evt(uVar3);
    break;
  case 3:
    iVar1 = r_hci_build_le_evt(uVar3);
    break;
  default:
    r_assert_param(0,"hci_tl.c",0x4a0);
    uVar4 = 0;
    uVar3 = 0;
    iVar1 = 0;
    goto _L119;
  case 5:
    iVar1 = r_hci_build_acl_data(uVar3);
    uVar3 = *(ushort *)(iVar1 + 2) + 4 & 0xffff;
    uVar4 = 2;
    goto _L119;
  }
  uVar4 = 4;
  uVar3 = *(byte *)(iVar1 + 1) + 2;
_L119:
  r_assert_err = (code)0x0;
  iVar2 = r_sdk_config_get_opts();
  if (*(char *)(iVar2 + 0x17) != '\x01') {
    r_h4tl_write(uVar4,iVar1,r_hci_tx_done);
    return;
  }
  *(undefined1 *)(iVar1 + -1) = uVar4;
  r_vhci_send_to_host(iVar1 + -1,uVar3 + 1);
  r_ke_event_set(5);
  return;
}

