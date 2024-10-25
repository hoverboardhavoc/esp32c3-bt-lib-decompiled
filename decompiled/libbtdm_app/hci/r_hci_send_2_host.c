/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  code *UNRECOVERED_JUMPTABLE;
  undefined1 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint uVar8;
  
  puVar2 = param_1 + -0xc;
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x7c))(puVar2,*(code **)(_r_ip_funcs_p + 0x7c));
  if (iVar4 == 0) {
    if (hci_ext_host != '\0') {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x5c);
      goto _L51;
    }
    uVar6 = 0;
    switch(*(short *)(param_1 + -8) + -0x1101) {
    case 0:
    case 1:
      if (*(short *)(param_1 + -4) != 0) {
        iVar4 = (**(code **)(_r_ip_funcs_p + 0x90))(*(code **)(_r_ip_funcs_p + 0x90));
        if (iVar4 == 0) goto _L34;
        uVar8 = (int)(uint)*(byte *)(iVar4 + 2) >> 4;
        goto _L46;
      }
      goto _L36;
    case 2:
      uVar1 = param_1[-4];
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x98);
      break;
    case 3:
      uVar1 = *param_1;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x9c);
      break;
    default:
      goto _L34;
    case 5:
      goto _L22;
    }
    iVar4 = (*UNRECOVERED_JUMPTABLE)(uVar1,UNRECOVERED_JUMPTABLE);
    if (iVar4 != 0) {
      uVar8 = (uint)*(byte *)(iVar4 + 1);
_L46:
      uVar8 = uVar8 & 3;
      if (uVar8 == 1) {
        uVar7 = *(ushort *)(param_1 + -6);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
        uVar5 = *(undefined2 *)(param_1 + -6);
        if (*(byte *)(iVar4 + 0xd) <= uVar7) {
          uVar6 = 0x3e6;
          UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
_L48:
          uVar3 = *(undefined2 *)(param_1 + -8);
          goto _L49;
        }
        iVar4 = (**(code **)(_r_hli_funcs_p + 0x14))(uVar5,*(code **)(_r_hli_funcs_p + 0x14));
        uVar7 = 9;
        if (iVar4 != 0xff) {
          uVar7 = (ushort)(iVar4 << 8) | 9;
        }
      }
      else if (uVar8 == 0) {
_L36:
        uVar7 = 8;
      }
      else {
        uVar3 = 3;
        uVar6 = 3;
        if (uVar8 != 2) goto _L21;
_L22:
        uVar7 = *(ushort *)(param_1 + -6);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(uVar6,*(code **)(_r_plf_funcs_p + 0x38));
        if (*(byte *)(iVar4 + 0xd) <= uVar7) {
          uVar6 = 0x3f7;
          UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
          uVar5 = *(undefined2 *)(param_1 + -6);
          goto _L48;
        }
        uVar7 = 5;
      }
      *(ushort *)(param_1 + -6) = uVar7;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0xe0);
      puVar2 = param_1;
      goto _L51;
    }
_L34:
    uVar3 = 4;
_L21:
    uVar6 = 0x3ff;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
    uVar5 = *(undefined2 *)(param_1 + -8);
_L49:
    (*UNRECOVERED_JUMPTABLE)(uVar3,uVar5,"hci.c",uVar6,UNRECOVERED_JUMPTABLE);
    (**(code **)(_r_plf_funcs_p + 0xc))
              (*(undefined2 *)(param_1 + -8),*(undefined2 *)(param_1 + -4),"hci.c",0x432,
               *(code **)(_r_plf_funcs_p + 0xc));
  }
  UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0xd8);
_L51:
                    /* WARNING: Could not recover jumptable at 0x000102a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(puVar2);
  return;
}

