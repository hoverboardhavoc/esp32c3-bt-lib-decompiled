/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_scan.o -> hci_le_set_scan_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_scan_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte abStack_21 [9];
  
  iVar5 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar5 + 0x23) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
    uVar6 = 0x20c;
    uVar4 = 0x802e0167;
_L30:
    r_ble_log_internal_x1(uVar4,uVar6);
    uVar6 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    uVar6 = 0;
    while( true ) {
      abStack_21[0] = (byte)uVar6;
      iVar5 = r_sdk_config_get_opts();
      uVar6 = (uint)abStack_21[0];
      if ((*(byte *)(iVar5 + 0xd) <= uVar6) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44 + 0x40) - 6U) < 3)) break;
      uVar6 = uVar6 + 1 & 0xff;
    }
    iVar5 = r_sdk_config_get_opts();
    uVar6 = (uint)abStack_21[0];
    if (uVar6 < *(byte *)(iVar5 + 0xd)) {
      uVar7 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44 + 0x40);
      if (uVar7 != 6) {
        uVar6 = uVar6 << 8 | uVar7 << 0x10 | 0xc;
        uVar4 = 0x802e0168;
        goto _L30;
      }
    }
    else {
      uVar6 = r_llm_activity_free_get(abStack_21);
      uVar7 = (uint)abStack_21[0];
      if (uVar6 != 0) {
        r_ble_log_internal_x1(0x802e0169,uVar7 << 8 | uVar6);
        goto _L26;
      }
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar7 * 0x44 + 0x40) = 6;
      r_ble_log_internal_x1(0x404e016a,uVar7 | 0x600);
    }
    uVar1 = *(ushort *)(param_1 + 4);
    uVar2 = *(ushort *)(param_1 + 2);
    if ((((uVar2 < uVar1) || (1 < *param_1)) || (0x3ffc < (ushort)(uVar1 - 4))) ||
       (0x3ffc < (ushort)(uVar2 - 4))) {
      r_ble_log_internal_x2(0x802e016b,CONCAT22(uVar2,uVar1),(uint)*param_1 << 8 | 0x12);
    }
    else {
      uVar6 = (uint)param_1[7];
      if ((param_1[6] | param_1[7]) < 4) {
        if ((*(char *)(_p_llm_env + 0xc6) != '\0') || (uVar6 < 2)) {
          piVar3 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
          if (*piVar3 == 0) {
            iVar5 = r_ke_msg_alloc(0,0,0,0x10);
            *piVar3 = iVar5;
          }
          iVar5 = *(int *)(_p_llm_env + 8);
          uVar6 = 0;
          pbVar8 = *(byte **)((uint)abStack_21[0] * 0x44 + iVar5);
          pbVar8[2] = 1;
          pbVar8[4] = *param_1;
          *(undefined2 *)(pbVar8 + 6) = *(undefined2 *)(param_1 + 2);
          *(undefined2 *)(pbVar8 + 8) = *(undefined2 *)(param_1 + 4);
          *pbVar8 = param_1[6];
          pbVar8[1] = param_1[7];
          *(undefined1 *)(iVar5 + (uint)abStack_21[0] * 0x44 + 0x40) = 6;
          r_ble_log_internal_x1(0x404e016e,abStack_21[0] | 0x600);
          goto _L26;
        }
        uVar6 = uVar6 << 0x10;
        uVar4 = 0x802e016d;
      }
      else {
        uVar6 = (uint)param_1[6] << 8 | uVar6 << 0x10;
        uVar4 = 0x802e016c;
      }
      r_ble_log_internal_x1(uVar4,uVar6 | 0x12);
    }
    uVar6 = 0x12;
  }
_L26:
  r_llm_cmd_cmp_send(param_2,uVar6);
  return 0;
}

