/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
               (int param_1,int param_2,undefined4 param_3,uint param_4,int param_5,int param_6,
               int param_7,int param_8)

{
  char cVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  undefined1 *puVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  ushort uVar11;
  int iVar12;
  uint uVar13;
  byte bStack00000000;
  byte in_stack_00000004;
  ushort *in_stack_00000008;
  undefined4 in_stack_0000000c;
  ushort *in_stack_00000010;
  int aiStack_54 [2];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  iVar12 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar10 = param_2 * 0xe;
  uVar2 = *(ushort *)(iVar5 + iVar10);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + iVar10) = uVar2 & 0x8000;
  uVar9 = -(uint)(param_5 != 0) & 6;
  iVar5 = (-param_6 & 6U) + uVar9;
  uVar4 = param_7 * 2 + iVar5 & 0xff;
  uVar13 = (-(_bStack00000000 & 0xff) & 0x12) + (-param_8 & 3U) + uVar4 & 0xff;
  if (in_stack_00000004 == 0) {
    if (uVar13 == 0) goto _L437;
  }
  else {
    uVar13 = uVar13 + 1 & 0xff;
  }
  uVar13 = uVar13 + 1 & 0xff;
_L437:
  if ((0xfe < *in_stack_00000010 + uVar13) && (param_8 == 0)) {
    if (uVar13 == 0) {
      uVar13 = 1;
    }
    uVar13 = uVar13 + 3 & 0xff;
    param_8 = 1;
  }
  if (param_6 != 0) {
    pvVar6 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (uVar9 + *in_stack_00000008 & 0xffff,
                                *(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(pvVar6,(void *)(iVar12 + 0x2c),6);
  }
  if (param_7 != 0) {
    puVar7 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))
                       (iVar5 + (uint)*in_stack_00000008 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    *puVar7 = *(undefined1 *)(iVar12 + 0x76);
    puVar7[1] = *(undefined1 *)(iVar12 + 0x77);
  }
  uVar4 = uVar4 + (-param_8 & 3U) & 0xff;
  if ((_bStack00000000 & 0xff) != 0) {
    aiStack_54[0] = *(int *)(iVar12 + 0x68) << 0x10;
    uVar3 = *(undefined2 *)(_p_lld_env + 0xd6);
    aiStack_54[1] = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    (**(code **)(_r_ip_funcs_p + 0x2fc))
              (*(undefined1 *)(iVar12 + 0x88),(int)&uStack_4c + 1,(int)&uStack_48 + 1,aiStack_54 + 1
               ,*(code **)(_r_ip_funcs_p + 0x2fc));
    uStack_4c = CONCAT31(uStack_4c._1_3_,(byte)uStack_4c & 0x1f | (char)uVar3 << 5);
    pvVar6 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (*in_stack_00000008 + uVar4 & 0xffff,
                                *(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(pvVar6,aiStack_54,0x12);
    uVar4 = uVar4 + 0x12 & 0xff;
  }
  if (in_stack_00000004 != 0) {
    cVar1 = *(char *)(iVar12 + 0x8d);
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x4f8))(*(code **)(_r_ip_funcs_p + 0x4f8));
    pcVar8 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (*in_stack_00000008 + uVar4 & 0xffff,
                                *(code **)(_r_plf_funcs_p + 0xbc));
    *pcVar8 = cVar1 + (char)(iVar5 / 10);
  }
  uVar2 = *in_stack_00000010;
  if (uVar2 != 0) {
    uVar4 = -uVar13 - 2 & 0xff;
    uVar11 = (ushort)uVar4;
    if (uVar2 < uVar4) {
      uVar11 = uVar2 & 0xff;
    }
    *in_stack_00000010 = uVar2 - uVar11;
  }
  if ((param_4 & 0xfc) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",500,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar5 = _r_ip_funcs_p;
  *(ushort *)(iVar10 + 6 + iVar12) =
       (ushort)in_stack_00000004 << 0xe | (ushort)(param_4 << 6) | (ushort)bStack00000000 << 0xd |
       (ushort)(param_7 << 0xb) | (ushort)(param_6 << 9) | (ushort)(param_5 << 8) | (ushort)uVar13 |
       (ushort)(param_8 << 0xc);
                    /* WARNING: Could not recover jumptable at 0x00012662. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar5 + 0x768))
            (param_1,param_2,param_3,param_5,param_6,param_8,in_stack_00000008,in_stack_0000000c);
  return;
}

