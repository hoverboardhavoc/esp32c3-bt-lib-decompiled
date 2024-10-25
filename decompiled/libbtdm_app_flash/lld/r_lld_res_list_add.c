/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_res_list_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
r_lld_res_list_add(void *param_1,void *param_2,void *param_3,uint param_4,int param_5,int param_6)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  
  local_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  iVar2 = memcmp(param_3,&local_50,0x10);
  iVar3 = memcmp(param_2,&local_50,0x10);
  uVar4 = r_lld_ral_search(param_1,param_4);
  if (uVar4 < 10) {
    uVar6 = 0x12;
  }
  else {
    uVar4 = 0;
    do {
      iVar5 = r_emi_get_mem_addr_by_offset(0xc60);
      if (-1 < *(short *)(iVar5 + uVar4 * 0x34)) {
        iVar5 = (uVar4 & 0xff) * 0x34;
        pvVar7 = (void *)r_emi_get_mem_addr_by_offset(iVar5 + 0xc78);
        memcpy(pvVar7,param_1,6);
        if (iVar2 != 0) {
          pvVar7 = (void *)r_emi_get_mem_addr_by_offset(iVar5 + 0xc7e);
          memcpy(pvVar7,param_3,0x10);
        }
        if (iVar3 != 0) {
          pvVar7 = (void *)r_emi_get_mem_addr_by_offset(iVar5 + 0xc62);
          memcpy(pvVar7,param_2,0x10);
        }
        uVar1 = (ushort)privacy_en;
        if ((param_4 & 0xfffffffe) != 0) {
          r_assert_err(0,"lld.c",0x66);
        }
        iVar5 = r_emi_get_mem_addr_by_offset(0xc60);
        *(ushort *)(iVar5 + uVar4 * 0x34) =
             uVar1 << 0xb | (ushort)(iVar3 != 0) << 1 | (ushort)(param_6 << 0xd) | (ushort)param_4 |
             (ushort)(param_5 << 0xe) | (ushort)(iVar2 != 0) << 6 | (ushort)(iVar2 != 0) << 5 |
             (ushort)(iVar3 != 0) << 2 | 0x8000;
        return 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != 10);
    uVar6 = 7;
  }
  return uVar6;
}

