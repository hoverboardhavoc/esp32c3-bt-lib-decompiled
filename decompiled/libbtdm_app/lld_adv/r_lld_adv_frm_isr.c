/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_isr(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  byte bVar9;
  code *UNRECOVERED_JUMPTABLE_00;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar2 == 0) {
    uVar7 = 0xb7e;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 8);
    goto _L983;
  }
  if ((*(char *)(iVar2 + 0x95) == '\0') || (iVar3 = iVar2 + 0x34, *(int *)(iVar2 + 0x38) != param_2)
     ) {
    iVar3 = iVar2;
  }
  (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3,1,*(code **)(_r_ip_funcs_p + 0x6b8));
  bVar9 = *(char *)(iVar2 + 0x86) + 1;
  *(byte *)(iVar2 + 0x86) = bVar9;
  if ((*(char *)(iVar2 + 0x89) == '\x02') ||
     ((*(ushort *)(iVar2 + 0x78) != 0 && (*(ushort *)(iVar2 + 0x78) <= (ushort)bVar9)))) {
    while (iVar3 = (**(code **)(_r_ip_funcs_p + 0x2a4))(param_1,*(code **)(_r_ip_funcs_p + 0x2a4)),
          iVar3 != 0) {
      (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
    }
    uVar7 = 0;
    if ((*(ushort *)(iVar2 + 0x78) != 0) &&
       (*(ushort *)(iVar2 + 0x78) <= (ushort)*(byte *)(iVar2 + 0x86))) {
      uVar7 = 0x43;
    }
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x1a0);
  }
  else {
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x1c4))
                      (*(undefined1 *)(iVar2 + 0x87),*(code **)(_r_ip_funcs_p + 0x1c4));
    if (iVar3 != 0) {
      uVar7 = 0;
      uVar6 = 0;
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x1a0);
      goto _L982;
    }
    if ((*(short *)(iVar2 + 0x24) != 0) &&
       (((*(ushort *)(iVar2 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar2 + 0x74) & 0x14) == 0x10))))
    {
      (**(code **)(_r_ip_funcs_p + 0x17c))
                (param_1,*(undefined1 *)(iVar2 + 0x28),1,1,*(code **)(_r_ip_funcs_p + 0x17c));
      *(undefined2 *)(iVar2 + 0x24) = 0;
    }
    if ((*(short *)(iVar2 + 0x26) != 0) &&
       (((*(ushort *)(iVar2 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar2 + 0x74) & 0x14) == 0x10))))
    {
      (**(code **)(_r_ip_funcs_p + 0x1d8))
                (param_1,*(undefined1 *)(iVar2 + 0x2a),1,1,*(code **)(_r_ip_funcs_p + 0x1d8));
      *(undefined2 *)(iVar2 + 0x26) = 0;
    }
    if (((*(ushort *)(iVar2 + 0x74) & 0x13) == 0) && (*(char *)(iVar2 + 0x94) != '\0')) {
      if (*(int *)(iVar2 + 0x68) != 0) {
        iVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        *(ushort *)(iVar2 + 0x76) =
             *(ushort *)(iVar2 + 0x76) & 0xf000 | (ushort)((uint)(iVar3 << 0x14) >> 0x14);
      }
      (**(code **)(_r_ip_funcs_p + 0x1ac))
                (*(undefined1 *)(iVar2 + 0x87),*(code **)(_r_ip_funcs_p + 0x1ac));
      *(undefined1 *)(iVar2 + 0x94) = 0;
    }
    bVar9 = DAT_0001705b;
    uVar1 = *(ushort *)(iVar2 + 0x74);
    if ((uVar1 & 8) == 0) {
      if (((uVar1 & 0x10) == 0) &&
         ((*(char *)(iVar2 + 0x95) == '\0' || (*(int *)(iVar2 + 0x38) == param_2)))) {
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
        if (*(char *)(iVar3 + 0x18) == '\0') {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xaf6,*(code **)(_r_plf_funcs_p + 8));
        }
        (**(code **)(_r_ip_funcs_p + 0x184))(param_1,*(code **)(_r_ip_funcs_p + 0x184));
      }
      if ((*(char *)(iVar2 + 0x95) == '\0') || (*(int *)(iVar2 + 0x38) != param_2)) {
        cVar8 = sch_slice_params;
        if (param_3 == 0) {
_L981:
          *(char *)(iVar2 + 0x16) = cVar8;
        }
        else if ((uint)(*(int *)(iVar2 + 100) << 1) <=
                 (param_2 - *(int *)(iVar2 + 0x5c) & 0xfffffffU)) {
          cVar8 = *(char *)(iVar2 + 0x16) + DAT_00017059;
          goto _L981;
        }
        *(int *)(iVar2 + 0x5c) = param_2;
        if (*(char *)(iVar2 + 0x95) != '\0') goto _L920;
_L923:
        if (*(int *)(iVar2 + 0x58) == -1) {
          *(ushort *)(iVar2 + 0x14) = DAT_00017059 & 0xf | 0x6000;
        }
        else {
          *(ushort *)(iVar2 + 0x14) = DAT_00017059 & 0xf | 0xa000;
          *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0x58);
        }
      }
      else {
        cVar8 = rwip_coex_cfg;
        if (param_3 == 0) {
_L980:
          *(char *)(iVar2 + 0x4a) = cVar8;
        }
        else if ((uint)(*(int *)(iVar2 + 100) << 1) <=
                 (param_2 - *(int *)(iVar2 + 0x60) & 0xfffffffU)) {
          cVar8 = *(char *)(iVar2 + 0x4a) + DAT_0001705d;
          goto _L980;
        }
        *(int *)(iVar2 + 0x60) = param_2;
_L920:
        if (*(int *)(iVar2 + 4) != param_2) goto _L923;
        *(ushort *)(iVar2 + 0x14) = DAT_00017059 & 0xf | 0xa000;
        *(uint *)(iVar2 + 0xc) = *(int *)(iVar2 + 0x38) - *(int *)(iVar2 + 100) & 0xfffffff;
      }
      uVar4 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
      uVar4 = uVar4 % 0x11;
      uVar5 = uVar4 << 1;
      if (*(char *)(iVar2 + 0x95) != '\0') {
        if (uVar4 == 0) {
          uVar5 = 1;
        }
        else if (uVar4 == 0x10) {
          uVar5 = 0x1f;
        }
      }
      uVar4 = uVar1 & 8;
      if (g_adv_delay_dis == '\0') {
        uVar4 = uVar5;
      }
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x6b0);
      *(uint *)(iVar2 + 4) = uVar4 + *(int *)(iVar2 + 100) * 2 + param_2 & 0xfffffff;
      iVar3 = (*UNRECOVERED_JUMPTABLE_00)(iVar2,UNRECOVERED_JUMPTABLE_00);
      cVar8 = *(char *)(iVar2 + 0x95);
      if (iVar3 == 0) {
        *(undefined1 *)(iVar2 + 0x89) = 0;
        if ((cVar8 != '\0') && (*(int *)(iVar2 + 0x38) == param_2)) {
          uVar4 = *(uint *)(iVar2 + 0x58);
          uVar5 = (uint)*(byte *)(iVar2 + 0x8f) * *(int *)(iVar2 + 100) * 2 + *(int *)(iVar2 + 4) &
                  0xfffffff;
          if (uVar4 == 0xffffffff) {
            *(ushort *)(iVar2 + 0x48) = DAT_0001705d & 0xf | 0x6000;
          }
          else {
            *(ushort *)(iVar2 + 0x48) = DAT_0001705d & 0xf | 0xa000;
            *(uint *)(iVar2 + 0x40) = uVar4;
            if ((uVar5 - uVar4 & 0xfffffff) < 0x7ffffff) {
              uVar5 = uVar4;
            }
          }
          *(uint *)(iVar2 + 0x38) = uVar5;
          iVar3 = (**(code **)(_r_ip_funcs_p + 0x6b0))
                            (iVar2 + 0x34,*(code **)(_r_ip_funcs_p + 0x6b0));
          if (iVar3 != 0) {
            *(undefined1 *)(iVar2 + 0x95) = 0;
            *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + 0x44);
          }
        }
        return;
      }
      if (cVar8 != '\0') {
        *(undefined4 *)(iVar2 + 4) = 0xffffffff;
        *(undefined1 *)(iVar2 + 0x89) = 0;
      }
      if (*(int *)(iVar2 + 0x58) == -1) {
        if (cVar8 != '\0') {
          return;
        }
        uVar7 = 0xb75;
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 8);
_L983:
                    /* WARNING: Could not recover jumptable at 0x00014e1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(0,"lld_adv.c",uVar7,UNRECOVERED_JUMPTABLE_00);
        return;
      }
      if (*(int *)(iVar2 + 0x58) != *(int *)(iVar2 + 0xc)) {
        return;
      }
    }
    else {
      cVar8 = DAT_0001705a;
      if (param_3 != 0) {
        cVar8 = *(char *)(iVar2 + 0x16) + DAT_0001705b;
      }
      *(char *)(iVar2 + 0x16) = cVar8;
      *(ushort *)(iVar2 + 0x14) = bVar9 & 0xf | 0xa000;
      *(int *)(iVar2 + 4) = param_2;
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 0x58);
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar2,*(code **)(_r_ip_funcs_p + 0x6b0));
      if (iVar3 == 0) {
        *(undefined1 *)(iVar2 + 0x89) = 0;
        return;
      }
    }
    uVar7 = 0x3c;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x1a0);
  }
  uVar6 = 1;
_L982:
                    /* WARNING: Could not recover jumptable at 0x00014aa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar6,uVar7,UNRECOVERED_JUMPTABLE_00);
  return;
}

