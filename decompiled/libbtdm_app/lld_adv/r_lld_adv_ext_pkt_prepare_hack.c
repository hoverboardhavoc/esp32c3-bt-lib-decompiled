/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_ext_pkt_prepare_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_ext_pkt_prepare_hack
               (int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
               int param_7,int param_8)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  void *pvVar6;
  undefined1 *puVar7;
  char *pcVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  ushort uVar12;
  int iVar13;
  byte in_stack_00000000;
  byte in_stack_00000004;
  ushort *in_stack_00000008;
  undefined4 in_stack_0000000c;
  ushort *in_stack_00000010;
  int aiStack_54 [2];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  iVar13 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar9 = param_2 * 0xe;
  uVar2 = *(ushort *)(iVar4 + iVar9);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar4 + iVar9) = uVar2 & 0x8000;
  uVar5 = 6;
  if (param_5 == 0) {
    uVar5 = 0;
  }
  uVar11 = uVar5;
  if (param_6 != 0) {
    uVar11 = uVar5 + 6;
  }
  uVar3 = uVar11;
  if (param_7 != 0) {
    uVar3 = uVar11 + 2;
  }
  uVar10 = uVar3;
  if (param_8 != 0) {
    uVar10 = uVar3 + 3;
  }
  if (in_stack_00000000 == 0) {
    if (in_stack_00000004 != 0) goto _L7;
    if (uVar10 == 0) goto _L10;
  }
  else {
    uVar10 = uVar10 + 0x12;
    if (in_stack_00000004 != 0) {
_L7:
      uVar10 = uVar10 + 1;
    }
  }
  uVar10 = uVar10 + 1 & 0xff;
_L10:
  if ((0xfe < *in_stack_00000010 + uVar10) && (param_8 == 0)) {
    if (uVar10 == 0) {
      uVar10 = 1;
    }
    uVar10 = uVar10 + 3 & 0xff;
    param_8 = 1;
  }
  if (param_6 != 0) {
    pvVar6 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (uVar5 + *in_stack_00000008 & 0xffff,
                                *(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(pvVar6,(void *)(iVar13 + 0x2c),6);
  }
  if (param_7 != 0) {
    puVar7 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))
                       (*in_stack_00000008 + uVar11 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
    *puVar7 = *(undefined1 *)(iVar13 + 0x76);
    puVar7[1] = *(undefined1 *)(iVar13 + 0x77);
  }
  if (param_8 != 0) {
    uVar3 = uVar3 + 3;
  }
  if (in_stack_00000000 != 0) {
    cVar1 = *(char *)(_p_lld_env + 0xd6);
    aiStack_54[0] = *(int *)(iVar13 + 0x68) << 0x10;
    aiStack_54[1] = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    (**(code **)(_r_ip_funcs_p + 0x2fc))
              (*(undefined1 *)(iVar13 + 0x88),(int)&uStack_4c + 1,(int)&uStack_48 + 1,aiStack_54 + 1
               ,*(code **)(_r_ip_funcs_p + 0x2fc));
    uStack_4c = CONCAT31(uStack_4c._1_3_,(byte)uStack_4c & 0x1f | cVar1 << 5);
    uVar5 = *in_stack_00000008 + uVar3;
    uVar3 = uVar3 + 0x12;
    pvVar6 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (uVar5 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(pvVar6,aiStack_54,0x12);
  }
  if (in_stack_00000004 != 0) {
    cVar1 = *(char *)(iVar13 + 0x8d);
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x4f8))(*(code **)(_r_ip_funcs_p + 0x4f8));
    pcVar8 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (*in_stack_00000008 + uVar3 & 0xffff,
                                *(code **)(_r_plf_funcs_p + 0xbc));
    *pcVar8 = cVar1 + (char)(iVar4 / 10);
  }
  uVar2 = *in_stack_00000010;
  if (uVar2 != 0) {
    uVar5 = -uVar10 - 2 & 0xff;
    uVar12 = (ushort)uVar5;
    if (uVar2 < uVar5) {
      uVar12 = uVar2 & 0xff;
    }
    *in_stack_00000010 = uVar2 - uVar12;
  }
  if ((param_4 << 6 & 0xffffff3fU) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",500,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar4 + iVar9 + 6) =
       (ushort)(param_8 << 0xc) | (ushort)(param_4 << 6) | (ushort)in_stack_00000004 << 0xe |
       (ushort)in_stack_00000000 << 0xd | (ushort)(param_7 << 0xb) | (ushort)(param_6 << 9) |
       (ushort)(param_5 << 8) | 0x3f;
  (**(code **)(_r_ip_funcs_p + 0x768))
            (param_1,param_2,param_3,param_5,param_6,param_8,in_stack_00000008,in_stack_0000000c);
  return;
}

