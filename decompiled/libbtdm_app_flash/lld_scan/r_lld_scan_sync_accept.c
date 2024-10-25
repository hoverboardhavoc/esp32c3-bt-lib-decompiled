/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_sync_accept
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_scan_sync_accept
               (int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
               uint param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 auStack_38 [20];
  
  uStack_48 = param_4;
  uStack_44 = param_5;
  if (*(char *)(_lld_scan_sync_env + 1) == '\x01') {
    if ((*(char *)(*(int *)(_lld_scan_env + param_1 * 4) + 0x44) != '\0') &&
       (iVar3 = r_emi_get_mem_addr_by_offset(0x1000), uVar1 = _DAT_6003113c,
       (*(ushort *)(param_2 * 0x14 + 2 + iVar3) >> 10 & 1) != 0)) {
      if ((_DAT_6003113c & 0xffff0000) != 0) {
        r_assert_err(0,"lld_scan.c",0x1c63);
      }
      uVar2 = (uVar1 & 0xffff) - 0xc00 >> 3 & 0xff;
      uVar1 = uVar2;
      do {
        if (uVar1 == 0) {
          uVar1 = 0xb;
        }
        else {
          uVar1 = uVar1 - 1 & 0xff;
        }
        iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
        if (*(short *)(iVar3 + uVar1 * 8) < 0) {
          iVar4 = r_emi_get_mem_addr_by_offset(0xc00);
          iVar3 = _lld_scan_sync_env;
          if ((*(ushort *)(iVar4 + uVar1 * 8) & 1) != 0) {
            memcpy((void *)(_lld_scan_sync_env + 4),&uStack_48,6);
            *(char *)(iVar3 + 3) = (char)param_3;
            return (int)(uint)*(ushort *)((uVar1 + 0x58) * 2 + _p_lld_env + 0xc) >> (param_6 & 0x1f)
                   & 1;
          }
          break;
        }
      } while (uVar2 != uVar1);
    }
    uVar1 = 0;
  }
  else {
    if (*(char *)(_lld_scan_env + 0x16) != '\0') {
      iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar3 = param_2 * 0x14 + 0xe;
      if (*(short *)(iVar4 + iVar3) != 0) {
        iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar1 = (*(ushort *)(iVar3 + iVar4) - 0xc60) / 0x34;
        pvVar5 = (void *)r_emi_get_mem_addr_by_offset((uVar1 & 0xff) * 0x34 + 0xc78);
        memcpy(auStack_38,pvVar5,6);
        iVar4 = r_emi_get_mem_addr_by_offset(0xc60);
        iVar3 = _lld_scan_sync_env;
        if ((ushort)*(byte *)(_lld_scan_sync_env + 3) !=
            (*(ushort *)((uVar1 & 0xff) * 0x34 + iVar4) & 1)) {
          return 0;
        }
        pvVar5 = (void *)(_lld_scan_sync_env + 4);
        iVar4 = memcmp(auStack_38,pvVar5,6);
        if (iVar4 != 0) {
          return 0;
        }
        if (*(byte *)(iVar3 + 2) != param_6) {
          return 0;
        }
        memcpy(pvVar5,&uStack_48,6);
        *(undefined1 *)(iVar3 + 3) = 1;
        return 1;
      }
    }
    iVar3 = _lld_scan_sync_env;
    uVar1 = 0;
    if ((*(byte *)(_lld_scan_sync_env + 3) == param_3) &&
       (iVar4 = memcmp(&uStack_48,(void *)(_lld_scan_sync_env + 4),6), iVar4 == 0)) {
      uVar1 = (uint)(*(byte *)(iVar3 + 2) == param_6);
    }
  }
  return uVar1;
}

