/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci.o -> r_hci_send_2_controller
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_send_2_controller(ushort *param_1)

{
  ushort uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  ushort uVar5;
  
  if (hci_ext_host != '\0') {
    r_assert_err(0,"hci.c",0x4cf);
    goto _L67;
  }
  uVar1 = param_1[-4];
  if (uVar1 == 0x1105) {
    iVar4 = r_hci_look_for_cmd_desc(param_1[-2]);
    if (iVar4 != 0) {
      uVar5 = *(byte *)(iVar4 + 2) & 0xf;
      if (uVar5 != 1) {
        if (((*(byte *)(iVar4 + 2) & 0xf) == 0) || (uVar5 == 2)) {
          uVar1 = 0;
          goto _L58;
        }
        uVar1 = 3;
        goto _L66;
      }
      goto _L57;
    }
  }
  else {
    uVar5 = 0x1106;
_L66:
    if (uVar1 == uVar5) {
_L57:
      uVar2 = *param_1 & 0xfff;
      pbVar3 = (byte *)r_sdk_config_get_hl_derived_opts();
      if ((uVar2 < *pbVar3) && (r_hci_look_for_le_evt_desc[uVar2] != (code)0x0)) {
        uVar1 = (ushort)(uVar2 << 8) | 1;
_L58:
        param_1[-3] = uVar1;
        r_ke_msg_send(param_1);
        return;
      }
    }
  }
  r_assert_warn(param_1[-4],param_1[-2],"hci.c",0x4c5);
_L67:
  r_ke_msg_free(param_1 + -6);
  return;
}

