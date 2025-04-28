/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_ext_pkt_prepare
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_ext_pkt_prepare
               (int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
               int param_7,int param_8)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  undefined1 *puVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  ushort uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  byte in_stack_00000000;
  byte in_stack_00000004;
  ushort *in_stack_00000008;
  undefined4 in_stack_0000000c;
  ushort *in_stack_00000010;
  int aiStack_54 [2];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  iVar11 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar12 = param_2 * 0xe;
  uVar2 = *(ushort *)(iVar4 + iVar12);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar4 + iVar12) = uVar2 & 0x8000;
  uVar8 = 6;
  if (param_5 == 0) {
    uVar8 = 0;
  }
  uVar13 = uVar8;
  if (param_6 != 0) {
    uVar13 = uVar8 + 6;
  }
  uVar3 = uVar13;
  if (param_7 != 0) {
    uVar3 = uVar13 + 2;
  }
  uVar9 = uVar3;
  if (param_8 != 0) {
    uVar9 = uVar3 + 3;
  }
  if (in_stack_00000000 == 0) {
    if (in_stack_00000004 != 0) goto _L473;
    if (uVar9 == 0) goto _L476;
  }
  else {
    uVar9 = uVar9 + 0x12;
    if (in_stack_00000004 != 0) {
_L473:
      uVar9 = uVar9 + 1;
    }
  }
  uVar9 = uVar9 + 1 & 0xff;
_L476:
  if ((0xfe < *in_stack_00000010 + uVar9) && (param_8 == 0)) {
    if (uVar9 == 0) {
      uVar9 = 1;
    }
    uVar9 = uVar9 + 3 & 0xff;
    param_8 = 1;
  }
  if (param_6 != 0) {
    pvVar5 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (*in_stack_00000008 + uVar8 & 0xffff,
                                *(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(pvVar5,(void *)(iVar11 + 0x2c),6);
  }
  if (param_7 != 0) {
    puVar6 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))
                       (*in_stack_00000008 + uVar13 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
    *puVar6 = *(undefined1 *)(iVar11 + 0x76);
    puVar6[1] = *(undefined1 *)(iVar11 + 0x77);
  }
  if (param_8 != 0) {
    uVar3 = uVar3 + 3;
  }
  if (in_stack_00000000 != 0) {
    cVar1 = *(char *)(_p_lld_env + 0xd6);
    aiStack_54[0] = *(int *)(iVar11 + 0x68) << 0x10;
    aiStack_54[1] = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    (**(code **)(_r_ip_funcs_p + 0x2fc))
              (*(undefined1 *)(iVar11 + 0x88),(int)&uStack_4c + 1,(int)&uStack_48 + 1,aiStack_54 + 1
               ,*(code **)(_r_ip_funcs_p + 0x2fc));
    uStack_4c = CONCAT31(uStack_4c._1_3_,(byte)uStack_4c & 0x1f | cVar1 << 5);
    uVar8 = *in_stack_00000008 + uVar3;
    uVar3 = uVar3 + 0x12;
    pvVar5 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (uVar8 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(pvVar5,aiStack_54,0x12);
  }
  if (in_stack_00000004 != 0) {
    cVar1 = *(char *)(iVar11 + 0x8d);
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x4f8))(*(code **)(_r_ip_funcs_p + 0x4f8));
    pcVar7 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (*in_stack_00000008 + uVar3 & 0xffff,
                                *(code **)(_r_plf_funcs_p + 0xbc));
    *pcVar7 = cVar1 + (char)(iVar4 / 10);
  }
  uVar2 = *in_stack_00000010;
  if (uVar2 != 0) {
    uVar8 = -uVar9 - 2 & 0xff;
    uVar10 = (ushort)uVar8;
    if (uVar2 < uVar8) {
      uVar10 = uVar2 & 0xff;
    }
    *in_stack_00000010 = uVar2 - uVar10;
  }
  if ((param_4 << 6 & 0xffffff3fU) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",500);
  }
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar12 + 6 + iVar4) =
       (ushort)in_stack_00000004 << 0xe | (ushort)(param_4 << 6) | (ushort)in_stack_00000000 << 0xd
       | (ushort)(param_7 << 0xb) | (ushort)(param_6 << 9) | (ushort)(param_5 << 8) | (ushort)uVar9
       | (ushort)(param_8 << 0xc);
                    /* WARNING: Could not recover jumptable at 0x0001273c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x768))
            (param_1,param_2,param_3,param_5,param_6,param_8,in_stack_00000008,in_stack_0000000c);
  return;
}

