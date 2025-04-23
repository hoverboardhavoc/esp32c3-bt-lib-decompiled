/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> hci_le_set_ext_scan_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_ext_scan_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  byte abStack_21 [9];
  
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar2 + 0x18) == '\0') ||
     (iVar2 = r_sdk_config_get_opts_ext(), *(char *)(iVar2 + 0x23) == '\0')) {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L36:
    uVar5 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar5 = 0;
    while( true ) {
      abStack_21[0] = (byte)uVar5;
      iVar2 = r_sdk_config_get_opts();
      uVar5 = (uint)abStack_21[0];
      if ((*(byte *)(iVar2 + 0xd) <= uVar5) ||
         ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar5 * 0x44 + 0x40) - 6U) < 3)) break;
      uVar5 = uVar5 + 1 & 0xff;
    }
    iVar2 = r_sdk_config_get_opts();
    if ((uint)abStack_21[0] < (uint)*(byte *)(iVar2 + 0xd)) {
      if (*(char *)((uint)abStack_21[0] * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x06')
      goto _L36;
    }
    else {
      uVar5 = r_llm_activity_free_get(abStack_21);
      if (uVar5 != 0) goto _L42;
    }
    uVar6 = (uint)param_1[2];
    if (uVar6 == 4) {
      uVar6 = 1;
_L41:
      pbVar4 = param_1 + 4;
      uVar3 = 0;
      do {
        if ((((*(ushort *)(pbVar4 + 2) < *(ushort *)(pbVar4 + 4)) || (1 < *pbVar4)) ||
            (*(ushort *)(pbVar4 + 4) < 4)) || (*(ushort *)(pbVar4 + 2) < 4)) {
          uVar5 = 0x12;
          if (uVar3 < uVar6) goto _L42;
          break;
        }
        uVar5 = uVar3 + 1;
        pbVar4 = pbVar4 + 6;
        uVar3 = 1;
      } while (uVar5 < uVar6);
      if ((*param_1 < 4) && (param_1[1] < 4)) {
        piVar7 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
        if (*piVar7 != 0) {
          r_ke_msg_free(*piVar7 + -0xc,uVar5);
          piVar7 = (int *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44);
          *piVar7 = 0;
        }
        *piVar7 = (int)param_1;
        *(undefined1 *)(piVar7 + 0x10) = 6;
        uVar5 = 0;
        uVar1 = 1;
        goto _L48;
      }
    }
    else {
      if (uVar6 == 5) {
        uVar6 = 2;
        goto _L41;
      }
      if (uVar6 == 1) goto _L41;
    }
    uVar5 = 0x12;
  }
_L42:
  uVar1 = 0;
_L48:
  r_llm_cmd_cmp_send(param_2,uVar5);
  return uVar1;
}

