/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci.o -> r_hci_basic_cmd_send_2_controller
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_basic_cmd_send_2_controller(undefined4 param_1)

{
  ushort uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  ushort *puVar5;
  ushort uVar6;
  
  puVar5 = (ushort *)r_ke_msg_alloc(0x1105,0,param_1,0);
  if (hci_ext_host != '\0') {
    r_assert_err(0,"hci.c",0x4cf);
    goto _L71;
  }
  uVar1 = puVar5[-4];
  if (uVar1 == 0x1105) {
    iVar4 = r_hci_look_for_cmd_desc(puVar5[-2]);
    if (iVar4 != 0) {
      uVar6 = *(byte *)(iVar4 + 2) & 0xf;
      if (uVar6 != 2) {
        if (2 < uVar6) {
          uVar1 = 3;
          goto _L70;
        }
        if ((*(byte *)(iVar4 + 2) & 0xf) != 0) goto _L63;
      }
      uVar1 = 0;
_L61:
      puVar5[-3] = uVar1;
      r_ke_msg_send(puVar5);
      return;
    }
  }
  else {
    uVar6 = 0x1106;
_L70:
    if (uVar1 == uVar6) {
_L63:
      uVar1 = *puVar5;
      pbVar3 = (byte *)r_sdk_config_get_hl_derived_opts();
      uVar2 = uVar1 & 0xfff;
      if ((uVar2 < *pbVar3) && (r_hci_look_for_le_evt_desc[uVar2] != (code)0x0)) {
        uVar1 = (ushort)(uVar2 << 8) | 1;
        goto _L61;
      }
    }
  }
  r_assert_warn(puVar5[-4],puVar5[-2],"hci.c",0x4c5);
_L71:
  r_ke_msg_free(puVar5 + -6);
  return;
}

