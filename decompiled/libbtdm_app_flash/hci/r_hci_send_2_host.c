/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint uVar8;
  
  puVar2 = param_1 + -0xc;
  iVar4 = r_hci_evt_mask_check(puVar2);
  if (iVar4 != 0) goto _L50;
  if (hci_ext_host != '\0') {
    r_hci_tl_send(puVar2);
    return;
  }
  uVar7 = *(ushort *)(param_1 + -8);
  if (uVar7 == 0x1104) {
    iVar4 = r_hci_look_for_le_evt_desc(*param_1);
_L52:
    if (iVar4 == 0) {
_L20:
      uVar3 = 4;
    }
    else {
      uVar8 = (uint)*(byte *)(iVar4 + 1);
_L46:
      uVar8 = uVar8 & 3;
      if (uVar8 == 1) {
        uVar7 = *(ushort *)(param_1 + -6);
        iVar4 = r_sdk_config_get_opts();
        uVar5 = *(undefined2 *)(param_1 + -6);
        if (uVar7 < *(byte *)(iVar4 + 0xd)) {
          uVar8 = (**(code **)(_r_hli_funcs_p + 0x14))(uVar5,*(code **)(_r_hli_funcs_p + 0x14));
          uVar7 = 9;
          if (uVar8 != 0xff) {
            uVar7 = (ushort)((uVar8 & 0xff) << 8) | 9;
          }
          goto _L29;
        }
        uVar6 = 0x3e6;
        goto _L48;
      }
      if (uVar8 == 2) goto _L21;
      uVar3 = 3;
      if (uVar8 == 0) goto _L22;
    }
    uVar5 = *(undefined2 *)(param_1 + -8);
    uVar6 = 0x3ff;
  }
  else {
    if (uVar7 < 0x1105) {
      if (uVar7 == 0x1103) {
        iVar4 = r_hci_look_for_evt_desc(param_1[-4]);
        goto _L52;
      }
      if (0x1100 < uVar7) {
        if (*(short *)(param_1 + -4) != 0) {
          iVar4 = r_hci_look_for_cmd_desc();
          if (iVar4 == 0) goto _L20;
          uVar8 = (int)(uint)*(byte *)(iVar4 + 2) >> 4;
          goto _L46;
        }
_L22:
        uVar7 = 8;
        goto _L29;
      }
      goto _L20;
    }
    if (uVar7 != 0x1106) goto _L20;
_L21:
    uVar1 = *(ushort *)(param_1 + -6);
    iVar4 = r_sdk_config_get_opts();
    uVar7 = 5;
    if (uVar1 < *(byte *)(iVar4 + 0xd)) {
_L29:
      *(ushort *)(param_1 + -6) = uVar7;
      r_ke_msg_send(param_1);
      return;
    }
    uVar5 = *(undefined2 *)(param_1 + -6);
    uVar6 = 0x3f7;
_L48:
    uVar3 = *(undefined2 *)(param_1 + -8);
  }
  r_assert_param(uVar3,uVar5,"hci.c",uVar6);
  r_assert_param(*(undefined2 *)(param_1 + -8),*(undefined2 *)(param_1 + -4),"hci.c",0x432);
_L50:
  r_ke_msg_free(puVar2);
  return;
}

