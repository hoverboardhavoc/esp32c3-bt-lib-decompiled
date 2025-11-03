/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_hci_le_set_ext_scan_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_scan_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  byte abStack_21 [9];
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L51:
    uVar7 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar7 = 0;
    while( true ) {
      abStack_21[0] = (byte)uVar7;
      iVar4 = r_sdk_config_get_opts();
      uVar7 = (uint)abStack_21[0];
      if (*(byte *)(iVar4 + 0xd) <= uVar7) break;
      if ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar7 * 0x44 + 0x40) - 6U) < 3) break;
      uVar7 = uVar7 + 1 & 0xff;
    }
    iVar4 = r_sdk_config_get_opts();
    uVar7 = (uint)abStack_21[0];
    if (uVar7 < *(byte *)(iVar4 + 0xd)) {
      uVar5 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + uVar7 * 0x44 + 0x40);
      if (uVar5 != 6) {
        r_ble_log_internal_x1(0x802e0177,uVar7 << 8 | uVar5 << 0x10 | 0xc);
        goto _L51;
      }
_L43:
      uVar5 = (uint)param_1[2];
      if (uVar5 != 1) {
        if (uVar5 == 4) {
          uVar5 = 1;
        }
        else {
          uVar7 = 0x12;
          if (uVar5 != 5) goto _L38;
          uVar5 = 2;
        }
      }
      pbVar6 = param_1 + 4;
      iVar4 = 0;
      do {
        uVar1 = *(ushort *)(pbVar6 + 4);
        uVar2 = *(ushort *)(pbVar6 + 2);
        if ((((uVar2 < uVar1) || (1 < *pbVar6)) || (uVar1 < 4)) || (uVar2 < 4)) {
          r_ble_log_internal_x2
                    (0x802e0179,CONCAT22(uVar2,uVar1),iVar4 << 8 | (uint)*pbVar6 << 0x10 | 0x12);
          goto _L62;
        }
        uVar7 = iVar4 + 1;
        pbVar6 = pbVar6 + 6;
        iVar4 = 1;
      } while (uVar7 < uVar5);
      if ((*param_1 | param_1[1]) < 4) {
        iVar4 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
        if (iVar4 != 0) {
          r_ke_msg_free(iVar4 + -0xc);
          *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44) = 0;
        }
        iVar4 = *(int *)(_p_llm_env + 8);
        uVar7 = 0;
        *(byte **)((uint)abStack_21[0] * 0x44 + iVar4) = param_1;
        uVar3 = 1;
        *(undefined1 *)(iVar4 + (uint)abStack_21[0] * 0x44 + 0x40) = 6;
        r_ble_log_internal_x1(0x404e017b,abStack_21[0] | 0x600);
        goto _L50;
      }
      r_ble_log_internal_x1(0x802e017a,(uint)*param_1 << 8 | (uint)param_1[1] << 0x10 | 0x12);
_L62:
      uVar7 = 0x12;
    }
    else {
      uVar7 = r_llm_activity_free_get(abStack_21);
      if (uVar7 == 0) goto _L43;
      r_ble_log_internal_x1(0x802e0178,(uint)abStack_21[0] << 8 | uVar7);
    }
  }
_L38:
  uVar3 = 0;
_L50:
  r_llm_cmd_cmp_send(param_2,uVar7);
  return uVar3;
}

