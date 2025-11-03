/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
      goto _L51;
    }
    uVar6 = *(ushort *)(param_1 + -8);
    if (uVar6 == 0x1104) {
      uVar1 = *param_1;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x9c);
_L53:
      iVar3 = (*UNRECOVERED_JUMPTABLE)(uVar1,UNRECOVERED_JUMPTABLE);
      if (iVar3 == 0) {
_L30:
        uVar2 = 4;
      }
      else {
        uVar7 = (uint)*(byte *)(iVar3 + 1);
_L45:
        uVar7 = uVar7 & 3;
        if (uVar7 == 1) {
          uVar6 = *(ushort *)(param_1 + -6);
          iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
          uVar4 = *(undefined2 *)(param_1 + -6);
          if (uVar6 < *(byte *)(iVar3 + 0xd)) {
            iVar3 = (**(code **)(_r_hli_funcs_p + 0x14))(uVar4,*(code **)(_r_hli_funcs_p + 0x14));
            uVar6 = 9;
            if (iVar3 != 0xff) {
              uVar6 = (ushort)(iVar3 << 8) | 9;
            }
            goto _L27;
          }
          uVar5 = 0x3ef;
          UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
          goto _L48;
        }
        if (uVar7 == 2) goto _L26;
        uVar2 = 3;
        if (uVar7 == 0) goto _L35;
      }
      uVar4 = *(undefined2 *)(param_1 + -8);
      UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
      uVar5 = 0x408;
    }
    else {
      if (uVar6 < 0x1105) {
        if (uVar6 == 0x1103) {
          uVar1 = param_1[-4];
          UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x98);
          goto _L53;
        }
        if (0x1100 < uVar6) {
          if (*(short *)(param_1 + -4) != 0) {
            iVar3 = (**(code **)(_r_ip_funcs_p + 0x90))(*(code **)(_r_ip_funcs_p + 0x90));
            if (iVar3 == 0) goto _L30;
            uVar7 = (int)(uint)*(byte *)(iVar3 + 2) >> 4;
            goto _L45;
          }
_L35:
          uVar6 = 8;
          goto _L27;
        }
        goto _L30;
      }
      if (uVar6 != 0x1106) goto _L30;
_L26:
      uVar6 = *(ushort *)(param_1 + -6);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (uVar6 < *(byte *)(iVar3 + 0xd)) {
        uVar6 = 5;
_L27:
        *(ushort *)(param_1 + -6) = uVar6;
        UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0xe0);
        puVar8 = param_1;
        goto _L51;
      }
      uVar4 = *(undefined2 *)(param_1 + -6);
      UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
      uVar5 = 0x400;
_L48:
      uVar2 = *(undefined2 *)(param_1 + -8);
    }
    (*UNRECOVERED_JUMPTABLE)(uVar2,uVar4,"hci.c",uVar5,UNRECOVERED_JUMPTABLE);
    (**(code **)(_r_plf_funcs_p + 0xc))
              (*(undefined2 *)(param_1 + -8),*(undefined2 *)(param_1 + -4),"hci.c",0x43b,
               *(code **)(_r_plf_funcs_p + 0xc));
  }
  UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0xd8);
_L51:
                    /* WARNING: Could not recover jumptable at 0x000102b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(puVar8,UNRECOVERED_JUMPTABLE);
  return;
}

