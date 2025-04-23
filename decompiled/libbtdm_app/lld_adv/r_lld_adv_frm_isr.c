/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_isr(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  byte bVar7;
  code *UNRECOVERED_JUMPTABLE_00;
  uint uVar8;
  
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    uVar5 = 0xae8;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 8);
    goto _L888;
  }
  if ((*(char *)(iVar1 + 0x95) == '\0') || (iVar2 = iVar1 + 0x34, *(int *)(iVar1 + 0x38) != param_2)
     ) {
    iVar2 = iVar1;
  }
  (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2,1,*(code **)(_r_ip_funcs_p + 0x6b8));
  bVar7 = *(char *)(iVar1 + 0x86) + 1;
  *(byte *)(iVar1 + 0x86) = bVar7;
  if ((*(char *)(iVar1 + 0x89) == '\x02') ||
     ((*(ushort *)(iVar1 + 0x78) != 0 && (*(ushort *)(iVar1 + 0x78) <= (ushort)bVar7)))) {
    while (iVar2 = (**(code **)(_r_ip_funcs_p + 0x2a4))(param_1,*(code **)(_r_ip_funcs_p + 0x2a4)),
          iVar2 != 0) {
      (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
    }
    uVar5 = 0;
    if ((*(ushort *)(iVar1 + 0x78) != 0) &&
       (uVar5 = 0x43, (ushort)*(byte *)(iVar1 + 0x86) < *(ushort *)(iVar1 + 0x78))) {
      uVar5 = 0;
    }
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x1a0);
  }
  else {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x1c4))
                      (*(undefined1 *)(iVar1 + 0x87),*(code **)(_r_ip_funcs_p + 0x1c4));
    if (iVar2 != 0) {
      uVar5 = 0;
      uVar4 = 0;
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x1a0);
      goto _L887;
    }
    if ((*(short *)(iVar1 + 0x24) != 0) &&
       (((*(ushort *)(iVar1 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))))
    {
      (**(code **)(_r_ip_funcs_p + 0x17c))
                (param_1,*(undefined1 *)(iVar1 + 0x28),1,*(code **)(_r_ip_funcs_p + 0x17c));
      *(undefined2 *)(iVar1 + 0x24) = 0;
    }
    if ((*(short *)(iVar1 + 0x26) != 0) &&
       (((*(ushort *)(iVar1 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))))
    {
      (**(code **)(_r_ip_funcs_p + 0x1d8))
                (param_1,*(undefined1 *)(iVar1 + 0x2a),1,*(code **)(_r_ip_funcs_p + 0x1d8));
      *(undefined2 *)(iVar1 + 0x26) = 0;
    }
    if (((*(ushort *)(iVar1 + 0x74) & 0x13) == 0) && (*(char *)(iVar1 + 0x94) != '\0')) {
      if (*(int *)(iVar1 + 0x68) != 0) {
        iVar2 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        *(ushort *)(iVar1 + 0x76) =
             *(ushort *)(iVar1 + 0x76) & 0xf000 | (ushort)((uint)(iVar2 << 0x14) >> 0x14);
      }
      (**(code **)(_r_ip_funcs_p + 0x1ac))
                (*(undefined1 *)(iVar1 + 0x87),*(code **)(_r_ip_funcs_p + 0x1ac));
      *(undefined1 *)(iVar1 + 0x94) = 0;
    }
    bVar7 = DAT_00017057;
    if ((*(ushort *)(iVar1 + 0x74) & 8) == 0) {
      if (((*(ushort *)(iVar1 + 0x74) & 0x10) == 0) &&
         ((*(char *)(iVar1 + 0x95) == '\0' || (*(int *)(iVar1 + 0x38) == param_2)))) {
        iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
        if (*(char *)(iVar2 + 0x18) == '\0') {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xa60,*(code **)(_r_plf_funcs_p + 8));
        }
        (**(code **)(_r_ip_funcs_p + 0x184))(param_1,*(code **)(_r_ip_funcs_p + 0x184));
      }
      if ((*(char *)(iVar1 + 0x95) == '\0') || (*(int *)(iVar1 + 0x38) != param_2)) {
        cVar6 = sch_slice_params;
        if (param_3 == 0) {
_L886:
          *(char *)(iVar1 + 0x16) = cVar6;
        }
        else if ((uint)(*(int *)(iVar1 + 100) << 1) <=
                 (param_2 - *(int *)(iVar1 + 0x5c) & 0xfffffffU)) {
          cVar6 = *(char *)(iVar1 + 0x16) + DAT_00017055;
          goto _L886;
        }
        *(int *)(iVar1 + 0x5c) = param_2;
        if (*(char *)(iVar1 + 0x95) != '\0') goto _L821;
_L824:
        if (*(int *)(iVar1 + 0x58) == -1) {
          *(ushort *)(iVar1 + 0x14) = DAT_00017055 & 0xf | 0x6000;
        }
        else {
          *(ushort *)(iVar1 + 0x14) = DAT_00017055 & 0xf | 0xa000;
          *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0x58);
        }
      }
      else {
        cVar6 = rwip_coex_cfg;
        if (param_3 == 0) {
_L885:
          *(char *)(iVar1 + 0x4a) = cVar6;
        }
        else if ((uint)(*(int *)(iVar1 + 100) << 1) <=
                 (param_2 - *(int *)(iVar1 + 0x60) & 0xfffffffU)) {
          cVar6 = *(char *)(iVar1 + 0x4a) + DAT_00017059;
          goto _L885;
        }
        *(int *)(iVar1 + 0x60) = param_2;
_L821:
        if (*(int *)(iVar1 + 4) != param_2) goto _L824;
        *(ushort *)(iVar1 + 0x14) = DAT_00017055 & 0xf | 0xa000;
        *(uint *)(iVar1 + 0xc) = *(int *)(iVar1 + 0x38) - *(int *)(iVar1 + 100) & 0xfffffff;
      }
      uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
      uVar8 = uVar3 % 0x11 << 1;
      if (*(char *)(iVar1 + 0x95) != '\0') {
        if (uVar8 < 0x20) {
          if (uVar3 % 0x11 == 0) {
            uVar8 = 1;
          }
        }
        else {
          uVar8 = 0x1f;
        }
      }
      *(uint *)(iVar1 + 4) =
           (uVar8 & -(uint)(g_adv_delay_dis == '\0')) + *(int *)(iVar1 + 100) * 2 + param_2 &
           0xfffffff;
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar1,*(code **)(_r_ip_funcs_p + 0x6b0));
      cVar6 = *(char *)(iVar1 + 0x95);
      if (iVar2 == 0) {
        *(undefined1 *)(iVar1 + 0x89) = 0;
        if (cVar6 == '\0') {
          return;
        }
        if (*(int *)(iVar1 + 0x38) != param_2) {
          return;
        }
        uVar3 = *(uint *)(iVar1 + 0x58);
        uVar8 = (uint)*(byte *)(iVar1 + 0x8f) * *(int *)(iVar1 + 100) * 2 + *(int *)(iVar1 + 4) &
                0xfffffff;
        if (uVar3 == 0xffffffff) {
          *(ushort *)(iVar1 + 0x48) = DAT_00017059 & 0xf | 0x6000;
        }
        else {
          *(ushort *)(iVar1 + 0x48) = DAT_00017059 & 0xf | 0xa000;
          *(uint *)(iVar1 + 0x40) = uVar3;
          if ((uVar8 - uVar3 & 0xfffffff) < 0x7ffffff) goto _L835;
        }
        uVar3 = uVar8;
_L835:
        iVar2 = _r_ip_funcs_p;
        *(uint *)(iVar1 + 0x38) = uVar3;
        iVar2 = (**(code **)(iVar2 + 0x6b0))(iVar1 + 0x34,*(code **)(iVar2 + 0x6b0));
        if (iVar2 != 0) {
          *(undefined1 *)(iVar1 + 0x95) = 0;
          *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 0x44);
        }
        return;
      }
      if (cVar6 != '\0') {
        *(undefined4 *)(iVar1 + 4) = 0xffffffff;
        *(undefined1 *)(iVar1 + 0x89) = 0;
      }
      if (*(int *)(iVar1 + 0x58) == -1) {
        if (cVar6 != '\0') {
          return;
        }
        uVar5 = 0xadf;
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 8);
_L888:
                    /* WARNING: Could not recover jumptable at 0x0001499a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(0,"lld_adv.c",uVar5,UNRECOVERED_JUMPTABLE_00);
        return;
      }
      if (*(int *)(iVar1 + 0x58) != *(int *)(iVar1 + 0xc)) {
        return;
      }
    }
    else {
      cVar6 = DAT_00017056;
      if (param_3 != 0) {
        cVar6 = *(char *)(iVar1 + 0x16) + DAT_00017057;
      }
      *(char *)(iVar1 + 0x16) = cVar6;
      *(ushort *)(iVar1 + 0x14) = bVar7 & 0xf | 0xa000;
      *(int *)(iVar1 + 4) = param_2;
      *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0x58);
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar1,*(code **)(_r_ip_funcs_p + 0x6b0));
      if (iVar2 == 0) {
        *(undefined1 *)(iVar1 + 0x89) = 0;
        return;
      }
    }
    uVar5 = 0x3c;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x1a0);
  }
  uVar4 = 1;
_L887:
                    /* WARNING: Could not recover jumptable at 0x00014618. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar4,uVar5,UNRECOVERED_JUMPTABLE_00);
  return;
}

