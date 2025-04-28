/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
    goto _L67;
  }
  uVar1 = puVar5[-4];
  if (uVar1 != 0x1105) {
    uVar6 = 0x1106;
    goto _L66;
  }
  iVar4 = r_hci_look_for_cmd_desc(puVar5[-2]);
  if (iVar4 != 0) {
    uVar6 = *(byte *)(iVar4 + 2) & 0xf;
    if (uVar6 == 2) {
_L61:
      uVar1 = 0;
_L57:
      puVar5[-3] = uVar1;
      r_ke_msg_send(puVar5);
      return;
    }
    if (uVar6 < 3) {
      uVar1 = 1;
      if ((*(byte *)(iVar4 + 2) & 0xf) == 0) goto _L61;
    }
    else {
      uVar1 = 3;
    }
_L66:
    if (uVar1 == uVar6) {
      uVar1 = *puVar5;
      pbVar3 = (byte *)r_sdk_config_get_hl_derived_opts();
      uVar2 = uVar1 & 0xfff;
      if ((uVar2 < *pbVar3) && (r_hci_look_for_le_evt_desc[uVar2] != (code)0x0)) {
        uVar1 = (ushort)(uVar2 << 8) | 1;
        goto _L57;
      }
    }
  }
  r_assert_warn(puVar5[-4],puVar5[-2],"hci.c",0x4c5);
_L67:
  r_ke_msg_free(puVar5 + -6);
  return;
}

