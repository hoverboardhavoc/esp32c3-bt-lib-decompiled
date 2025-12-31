/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> hci.o -> r_hci_send_2_host
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_send_2_host(undefined1 *param_1)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  ushort uVar8;
  uint uVar9;
  
  puVar2 = param_1 + -0xc;
  if (*(short *)(param_1 + -8) == 0x1106) {
    uVar4 = 0x200701f4;
    uVar7 = 0x1106;
  }
  else {
    uVar4 = 0x200701f5;
    uVar7 = CONCAT22(*(undefined2 *)(param_1 + -4),*(short *)(param_1 + -8));
  }
  r_ble_log_internal_x1(uVar4,uVar7);
  iVar5 = r_hci_evt_mask_check(puVar2);
  if (iVar5 != 0) goto _L49;
  if (hci_ext_host != '\0') {
    r_hci_tl_send(puVar2);
    return;
  }
  uVar8 = *(ushort *)(param_1 + -8);
  if (uVar8 == 0x1104) {
    iVar5 = r_hci_look_for_le_evt_desc(*param_1);
_L51:
    if (iVar5 == 0) {
_L27:
      uVar3 = 4;
    }
    else {
      uVar9 = (uint)*(byte *)(iVar5 + 1);
_L44:
      uVar9 = uVar9 & 3;
      if (uVar9 == 1) {
        uVar8 = *(ushort *)(param_1 + -6);
        iVar5 = r_sdk_config_get_opts();
        uVar6 = *(undefined2 *)(param_1 + -6);
        if (uVar8 < *(byte *)(iVar5 + 0xd)) {
          uVar9 = (**(code **)(_r_hli_funcs_p + 0x14))(uVar6,*(code **)(_r_hli_funcs_p + 0x14));
          uVar8 = 9;
          if (uVar9 != 0xff) {
            uVar8 = (ushort)((uVar9 & 0xff) << 8) | 9;
          }
          goto _L24;
        }
        uVar7 = 0x3ef;
        goto _L47;
      }
      if (uVar9 == 2) goto _L23;
      uVar3 = 3;
      if (uVar9 == 0) {
        uVar8 = 8;
        goto _L24;
      }
    }
    uVar6 = *(undefined2 *)(param_1 + -8);
    uVar7 = 0x408;
  }
  else {
    if (uVar8 < 0x1105) {
      if (uVar8 == 0x1103) {
        iVar5 = r_hci_look_for_evt_desc(param_1[-4]);
        goto _L51;
      }
      if (0x1100 < uVar8) {
        uVar8 = 8;
        if (*(short *)(param_1 + -4) == 0) goto _L24;
        iVar5 = r_hci_look_for_cmd_desc();
        if (iVar5 == 0) goto _L27;
        uVar9 = (int)(uint)*(byte *)(iVar5 + 2) >> 4;
        goto _L44;
      }
      goto _L27;
    }
    if (uVar8 != 0x1106) goto _L27;
_L23:
    uVar1 = *(ushort *)(param_1 + -6);
    iVar5 = r_sdk_config_get_opts();
    uVar8 = 5;
    if (uVar1 < *(byte *)(iVar5 + 0xd)) {
_L24:
      *(ushort *)(param_1 + -6) = uVar8;
      r_ke_msg_send(param_1);
      return;
    }
    uVar6 = *(undefined2 *)(param_1 + -6);
    uVar7 = 0x400;
_L47:
    uVar3 = *(undefined2 *)(param_1 + -8);
  }
  r_assert_param(uVar3,uVar6,"hci.c",uVar7);
  r_assert_param(*(undefined2 *)(param_1 + -8),*(undefined2 *)(param_1 + -4),"hci.c",0x43b);
_L49:
  r_ke_msg_free(puVar2);
  return;
}

