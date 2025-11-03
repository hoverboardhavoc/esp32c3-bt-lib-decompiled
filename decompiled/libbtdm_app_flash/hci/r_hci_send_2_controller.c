/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
    r_assert_err(0,"hci.c",0x4d8);
    goto _L70;
  }
  uVar1 = param_1[-4];
  if (uVar1 != 0x1105) {
    uVar5 = 0x1106;
    goto _L69;
  }
  iVar4 = r_hci_look_for_cmd_desc(param_1[-2]);
  if (iVar4 != 0) {
    uVar5 = *(byte *)(iVar4 + 2) & 0xf;
    if (uVar5 == 2) {
_L64:
      uVar1 = 0;
_L60:
      param_1[-3] = uVar1;
      r_ke_msg_send(param_1);
      return;
    }
    if (uVar5 < 3) {
      uVar1 = 1;
      if ((*(byte *)(iVar4 + 2) & 0xf) == 0) goto _L64;
    }
    else {
      uVar1 = 3;
    }
_L69:
    if (uVar1 == uVar5) {
      uVar1 = *param_1;
      pbVar3 = (byte *)r_sdk_config_get_hl_derived_opts();
      uVar2 = uVar1 & 0xfff;
      if ((uVar2 < *pbVar3) && (r_hci_look_for_evt_desc[uVar2] != (code)0x0)) {
        uVar1 = (ushort)(uVar2 << 8) | 1;
        goto _L60;
      }
    }
  }
  r_assert_warn(param_1[-4],param_1[-2],"hci.c",0x4ce);
_L70:
  r_ke_msg_free(param_1 + -6);
  return;
}

