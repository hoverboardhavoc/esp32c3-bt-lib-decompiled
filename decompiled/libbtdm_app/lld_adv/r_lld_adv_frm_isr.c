/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_isr(int param_1,int param_2,int param_3)

{
  code *UNRECOVERED_JUMPTABLE_00;
  int iVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  char cVar8;
  byte bVar9;
  
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    uVar6 = 0xad0;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 8);
    goto _L927;
  }
  if ((*(char *)(iVar1 + 0x95) == '\0') || (iVar3 = iVar1 + 0x34, *(int *)(iVar1 + 0x38) != param_2)
     ) {
    iVar3 = iVar1;
  }
  (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3,1,*(code **)(_r_ip_funcs_p + 0x6b8));
  bVar9 = *(char *)(iVar1 + 0x86) + 1;
  *(byte *)(iVar1 + 0x86) = bVar9;
  if ((*(char *)(iVar1 + 0x89) == '\x02') ||
     ((*(ushort *)(iVar1 + 0x78) != 0 && (*(ushort *)(iVar1 + 0x78) <= (ushort)bVar9)))) {
    while (iVar3 = (**(code **)(_r_ip_funcs_p + 0x2a4))(param_1,*(code **)(_r_ip_funcs_p + 0x2a4)),
          iVar3 != 0) {
      (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
    }
    uVar6 = 0;
    if ((*(ushort *)(iVar1 + 0x78) != 0) &&
       (*(ushort *)(iVar1 + 0x78) <= (ushort)*(byte *)(iVar1 + 0x86))) {
      uVar6 = 0x43;
    }
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x1a0);
  }
  else {
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x1c4))
                      (*(undefined1 *)(iVar1 + 0x87),*(code **)(_r_ip_funcs_p + 0x1c4));
    if (iVar3 != 0) {
      uVar6 = 0;
      uVar5 = 0;
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x1a0);
      goto _L926;
    }
    if ((*(short *)(iVar1 + 0x24) != 0) &&
       (((*(ushort *)(iVar1 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))))
    {
      (**(code **)(_r_ip_funcs_p + 0x17c))
                (param_1,*(undefined1 *)(iVar1 + 0x28),1,1,*(code **)(_r_ip_funcs_p + 0x17c));
      *(undefined2 *)(iVar1 + 0x24) = 0;
    }
    if ((*(short *)(iVar1 + 0x26) != 0) &&
       (((*(ushort *)(iVar1 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))))
    {
      (**(code **)(_r_ip_funcs_p + 0x1d8))
                (param_1,*(undefined1 *)(iVar1 + 0x2a),1,1,*(code **)(_r_ip_funcs_p + 0x1d8));
      *(undefined2 *)(iVar1 + 0x26) = 0;
    }
    if (((*(ushort *)(iVar1 + 0x74) & 0x13) == 0) && (*(char *)(iVar1 + 0x94) != '\0')) {
      if (*(int *)(iVar1 + 0x68) != 0) {
        uVar2 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        *(ushort *)(iVar1 + 0x76) = *(ushort *)(iVar1 + 0x76) & 0xf000 | uVar2 & 0xfff;
      }
      (**(code **)(_r_ip_funcs_p + 0x1ac))
                (*(undefined1 *)(iVar1 + 0x87),*(code **)(_r_ip_funcs_p + 0x1ac));
      *(undefined1 *)(iVar1 + 0x94) = 0;
    }
    bVar9 = DAT_0001705b;
    if ((*(ushort *)(iVar1 + 0x74) & 8) == 0) {
      if ((*(ushort *)(iVar1 + 0x74) & 0x10) == 0) {
        if ((*(char *)(iVar1 + 0x95) == '\0') || (*(int *)(iVar1 + 0x38) == param_2)) {
          iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
          if (*(char *)(iVar3 + 0x18) == '\0') {
            (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xa48,*(code **)(_r_plf_funcs_p + 8));
          }
          (**(code **)(_r_ip_funcs_p + 0x184))(param_1,*(code **)(_r_ip_funcs_p + 0x184));
          goto _L858;
        }
_L860:
        cVar8 = sch_slice_params;
        if (param_3 == 0) {
_L925:
          *(char *)(iVar1 + 0x16) = cVar8;
        }
        else if ((uint)(*(int *)(iVar1 + 100) << 1) <=
                 (param_2 - *(int *)(iVar1 + 0x5c) & 0xfffffffU)) {
          cVar8 = *(char *)(iVar1 + 0x16) + DAT_00017059;
          goto _L925;
        }
        *(int *)(iVar1 + 0x5c) = param_2;
        if (*(char *)(iVar1 + 0x95) != '\0') goto _L866;
_L869:
        if (*(int *)(iVar1 + 0x58) == -1) {
          *(ushort *)(iVar1 + 0x14) = DAT_00017059 & 0xf | 0x6000;
        }
        else {
          *(ushort *)(iVar1 + 0x14) = DAT_00017059 & 0xf | 0xa000;
          *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0x58);
        }
      }
      else {
_L858:
        if ((*(char *)(iVar1 + 0x95) == '\0') || (*(int *)(iVar1 + 0x38) != param_2)) goto _L860;
        cVar8 = rwip_coex_cfg;
        if (param_3 == 0) {
_L924:
          *(char *)(iVar1 + 0x4a) = cVar8;
        }
        else if ((uint)(*(int *)(iVar1 + 100) << 1) <=
                 (param_2 - *(int *)(iVar1 + 0x60) & 0xfffffffU)) {
          cVar8 = *(char *)(iVar1 + 0x4a) + DAT_0001705d;
          goto _L924;
        }
        *(int *)(iVar1 + 0x60) = param_2;
_L866:
        if (*(int *)(iVar1 + 4) != param_2) goto _L869;
        *(ushort *)(iVar1 + 0x14) = DAT_00017059 & 0xf | 0xa000;
        *(uint *)(iVar1 + 0xc) = *(int *)(iVar1 + 0x38) - *(int *)(iVar1 + 100) & 0xfffffff;
      }
      uVar4 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
      uVar4 = uVar4 % 0x11;
      iVar3 = uVar4 << 1;
      if (*(char *)(iVar1 + 0x95) != '\0') {
        if (uVar4 == 0) {
          iVar3 = 1;
        }
        else if (uVar4 == 0x10) {
          iVar3 = 0x1f;
        }
      }
      if (g_adv_delay_dis != '\0') {
        iVar3 = 0;
      }
      *(uint *)(iVar1 + 4) = iVar3 + *(int *)(iVar1 + 100) * 2 + param_2 & 0xfffffff;
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar1,*(code **)(_r_ip_funcs_p + 0x6b0));
      cVar8 = *(char *)(iVar1 + 0x95);
      if (iVar3 == 0) {
        *(undefined1 *)(iVar1 + 0x89) = 0;
        if ((cVar8 != '\0') && (*(int *)(iVar1 + 0x38) == param_2)) {
          uVar7 = *(uint *)(iVar1 + 0x58);
          uVar4 = (uint)*(byte *)(iVar1 + 0x8f) * *(int *)(iVar1 + 100) * 2 + *(int *)(iVar1 + 4) &
                  0xfffffff;
          if (uVar7 == 0xffffffff) {
            *(ushort *)(iVar1 + 0x48) = DAT_0001705d & 0xf | 0x6000;
          }
          else {
            *(ushort *)(iVar1 + 0x48) = DAT_0001705d & 0xf | 0xa000;
            *(uint *)(iVar1 + 0x40) = uVar7;
            if ((uVar4 - uVar7 & 0xfffffff) < 0x7ffffff) {
              uVar4 = uVar7;
            }
          }
          *(uint *)(iVar1 + 0x38) = uVar4;
          iVar3 = (**(code **)(_r_ip_funcs_p + 0x6b0))
                            (iVar1 + 0x34,*(code **)(_r_ip_funcs_p + 0x6b0));
          if (iVar3 != 0) {
            *(undefined1 *)(iVar1 + 0x95) = 0;
            *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 0x44);
          }
        }
        return;
      }
      if (cVar8 != '\0') {
        *(undefined4 *)(iVar1 + 4) = 0xffffffff;
        *(undefined1 *)(iVar1 + 0x89) = 0;
      }
      if (*(int *)(iVar1 + 0x58) == -1) {
        if (cVar8 != '\0') {
          return;
        }
        uVar6 = 0xac7;
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 8);
_L927:
                    /* WARNING: Could not recover jumptable at 0x0001496a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(0,"lld_adv.c",uVar6);
        return;
      }
      if (*(int *)(iVar1 + 0x58) != *(int *)(iVar1 + 0xc)) {
        return;
      }
    }
    else {
      cVar8 = DAT_0001705a;
      if (param_3 != 0) {
        cVar8 = *(char *)(iVar1 + 0x16) + DAT_0001705b;
      }
      *(char *)(iVar1 + 0x16) = cVar8;
      *(ushort *)(iVar1 + 0x14) = bVar9 & 0xf | 0xa000;
      *(int *)(iVar1 + 4) = param_2;
      *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0x58);
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar1,*(code **)(_r_ip_funcs_p + 0x6b0));
      if (iVar3 == 0) {
        *(undefined1 *)(iVar1 + 0x89) = 0;
        return;
      }
    }
    uVar6 = 0x3c;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x1a0);
  }
  uVar5 = 1;
_L926:
                    /* WARNING: Could not recover jumptable at 0x000145ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar5,uVar6);
  return;
}

