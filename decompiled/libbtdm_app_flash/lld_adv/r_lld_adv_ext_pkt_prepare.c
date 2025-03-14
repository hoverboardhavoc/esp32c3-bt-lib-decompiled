/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_pkt_prepare
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
  uint uVar5;
  void *pvVar6;
  undefined1 *puVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
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
  iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar11 = param_2 * 0xe;
  uVar2 = *(ushort *)(iVar4 + iVar11);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar4 + iVar11) = uVar2 & 0x8000;
  uVar5 = 6;
  if (param_5 == 0) {
    uVar5 = 0;
  }
  uVar9 = uVar5;
  if (param_6 != 0) {
    uVar9 = uVar5 + 6;
  }
  uVar3 = uVar9;
  if (param_7 != 0) {
    uVar3 = uVar9 + 2;
  }
  uVar10 = uVar3;
  if (param_8 != 0) {
    uVar10 = uVar3 + 3;
  }
  if (in_stack_00000000 == 0) {
    if (in_stack_00000004 != 0) goto _L519;
    if (uVar10 == 0) goto _L522;
  }
  else {
    uVar10 = uVar10 + 0x12;
    if (in_stack_00000004 != 0) {
_L519:
      uVar10 = uVar10 + 1;
    }
  }
  uVar10 = uVar10 + 1 & 0xff;
_L522:
  if ((0xfe < *in_stack_00000010 + uVar10) && (param_8 == 0)) {
    if (uVar10 == 0) {
      uVar10 = 1;
    }
    uVar10 = uVar10 + 3 & 0xff;
    param_8 = 1;
  }
  if (param_6 != 0) {
    pvVar6 = (void *)r_emi_get_mem_addr_by_offset(uVar5 + *in_stack_00000008 & 0xffff);
    memcpy(pvVar6,(void *)(iVar13 + 0x2c),6);
  }
  if (param_7 != 0) {
    puVar7 = (undefined1 *)r_emi_get_mem_addr_by_offset(*in_stack_00000008 + uVar9 & 0xffff);
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
    r_lld_per_adv_init_info_get
              (*(undefined1 *)(iVar13 + 0x88),(int)&uStack_4c + 1,(int)&uStack_48 + 1,aiStack_54 + 1
              );
    uStack_4c = CONCAT31(uStack_4c._1_3_,(byte)uStack_4c & 0x1f | cVar1 << 5);
    pvVar6 = (void *)r_emi_get_mem_addr_by_offset(*in_stack_00000008 + uVar3 & 0xffff);
    uVar3 = uVar3 + 0x12;
    memcpy(pvVar6,aiStack_54,0x12);
  }
  if (in_stack_00000004 != 0) {
    cVar1 = *(char *)(iVar13 + 0x8d);
    iVar4 = r_llm_tx_path_comp_get();
    pcVar8 = (char *)r_emi_get_mem_addr_by_offset(*in_stack_00000008 + uVar3 & 0xffff);
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
    r_assert_err(0,"lld_adv.c",500);
  }
  iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar11 + 6 + iVar4) =
       (ushort)in_stack_00000004 << 0xe | (ushort)(param_4 << 6) | (ushort)in_stack_00000000 << 0xd
       | (ushort)(param_7 << 0xb) | (ushort)(param_6 << 9) | (ushort)(param_5 << 8) | (ushort)uVar10
       | (ushort)(param_8 << 0xc);
  r_lld_adv_ext_pkt_prepare_set
            (param_1,param_2,param_3,param_5,param_6,param_8,in_stack_00000008,in_stack_0000000c);
  return;
}

