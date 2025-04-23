/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci.o -> r_hci_send_2_host
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_send_2_host(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  ushort uVar6;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar7;
  undefined1 *puVar8;
  
  puVar8 = param_1 + -0xc;
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x7c))(puVar8,*(code **)(_r_ip_funcs_p + 0x7c));
  if (iVar3 == 0) {
    if (hci_ext_host != '\0') {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x5c);
      goto _L56;
    }
    uVar6 = *(ushort *)(param_1 + -8);
    if (uVar6 == 0x1104) {
      uVar1 = *param_1;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x9c);
_L58:
      iVar3 = (*UNRECOVERED_JUMPTABLE)(uVar1,UNRECOVERED_JUMPTABLE);
      if (iVar3 == 0) {
_L25:
        uVar2 = 4;
      }
      else {
        uVar7 = (uint)*(byte *)(iVar3 + 1);
_L51:
        uVar7 = uVar7 & 3;
        if (uVar7 == 1) {
          uVar6 = *(ushort *)(param_1 + -6);
          iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
          uVar4 = *(undefined2 *)(param_1 + -6);
          if (uVar6 < *(byte *)(iVar3 + 0xd)) {
            uVar7 = (**(code **)(_r_hli_funcs_p + 0x14))(uVar4,*(code **)(_r_hli_funcs_p + 0x14));
            uVar6 = 9;
            if (uVar7 != 0xff) {
              uVar6 = (ushort)((uVar7 & 0xff) << 8) | 9;
            }
            goto _L34;
          }
          uVar5 = 0x3e6;
          UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
          goto _L53;
        }
        if (uVar7 == 2) goto _L26;
        uVar2 = 3;
        if (uVar7 == 0) goto _L27;
      }
      uVar4 = *(undefined2 *)(param_1 + -8);
      UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
      uVar5 = 0x3ff;
    }
    else {
      if (uVar6 < 0x1105) {
        if (uVar6 == 0x1103) {
          uVar1 = param_1[-4];
          UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x98);
          goto _L58;
        }
        if (0x1100 < uVar6) {
          if (*(short *)(param_1 + -4) != 0) {
            iVar3 = (**(code **)(_r_ip_funcs_p + 0x90))(*(code **)(_r_ip_funcs_p + 0x90));
            if (iVar3 == 0) goto _L25;
            uVar7 = (int)(uint)*(byte *)(iVar3 + 2) >> 4;
            goto _L51;
          }
_L27:
          uVar6 = 8;
          goto _L34;
        }
        goto _L25;
      }
      if (uVar6 != 0x1106) goto _L25;
_L26:
      uVar6 = *(ushort *)(param_1 + -6);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (uVar6 < *(byte *)(iVar3 + 0xd)) {
        uVar6 = 5;
_L34:
        *(ushort *)(param_1 + -6) = uVar6;
        UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0xe0);
        puVar8 = param_1;
        goto _L56;
      }
      uVar4 = *(undefined2 *)(param_1 + -6);
      UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
      uVar5 = 0x3f7;
_L53:
      uVar2 = *(undefined2 *)(param_1 + -8);
    }
    (*UNRECOVERED_JUMPTABLE)(uVar2,uVar4,"hci.c",uVar5,UNRECOVERED_JUMPTABLE);
    (**(code **)(_r_plf_funcs_p + 0xc))
              (*(undefined2 *)(param_1 + -8),*(undefined2 *)(param_1 + -4),"hci.c",0x432,
               *(code **)(_r_plf_funcs_p + 0xc));
  }
  UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0xd8);
_L56:
                    /* WARNING: Could not recover jumptable at 0x000102b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(puVar8,UNRECOVERED_JUMPTABLE);
  return;
}

