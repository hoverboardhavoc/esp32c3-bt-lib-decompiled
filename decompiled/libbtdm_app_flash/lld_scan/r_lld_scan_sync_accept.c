/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 auStack_38 [20];
  
  uStack_48 = param_4;
  uStack_44 = param_5;
  if (*(char *)(_lld_scan_sync_env + 1) == '\x01') {
    if ((*(char *)(*(int *)(_lld_scan_env + param_1 * 4) + 0x44) != '\0') &&
       (iVar2 = r_emi_get_mem_addr_by_offset(0x1000), uVar1 = _DAT_6003113c,
       (*(ushort *)(param_2 * 0x14 + 2 + iVar2) >> 10 & 1) != 0)) {
      if ((_DAT_6003113c & 0xffff0000) != 0) {
        r_assert_err(0,"lld_scan.c",0x1c63);
      }
      uVar5 = (uVar1 & 0xffff) - 0xc00 >> 3 & 0xff;
      uVar1 = uVar5;
      do {
        if (uVar1 == 0) {
          uVar1 = 0xb;
        }
        else {
          uVar1 = uVar1 - 1 & 0xff;
        }
        iVar2 = r_emi_get_mem_addr_by_offset(0xc00);
        if (*(short *)(iVar2 + uVar1 * 8) < 0) {
          iVar3 = r_emi_get_mem_addr_by_offset(0xc00);
          iVar2 = _lld_scan_sync_env;
          if ((*(ushort *)(uVar1 * 8 + iVar3) & 1) != 0) {
            memcpy((void *)(_lld_scan_sync_env + 4),&uStack_48,6);
            *(char *)(iVar2 + 3) = (char)param_3;
            return (int)(uint)*(ushort *)(_p_lld_env + (uVar1 + 0x58) * 2 + 0xc) >> (param_6 & 0x1f)
                   & 1;
          }
          break;
        }
      } while (uVar5 != uVar1);
    }
    uVar1 = 0;
  }
  else {
    if (*(char *)(_lld_scan_env + 0x16) != '\0') {
      iVar3 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar2 = param_2 * 0x14 + 0xe;
      if (*(short *)(iVar3 + iVar2) != 0) {
        iVar3 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar1 = (*(ushort *)(iVar2 + iVar3) - 0xc60) / 0x34;
        pvVar4 = (void *)r_emi_get_mem_addr_by_offset((uVar1 & 0xff) * 0x34 + 0xc78);
        memcpy(auStack_38,pvVar4,6);
        iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
        iVar2 = _lld_scan_sync_env;
        if ((ushort)*(byte *)(_lld_scan_sync_env + 3) !=
            (*(ushort *)((uVar1 & 0xff) * 0x34 + iVar3) & 1)) {
          return 0;
        }
        pvVar4 = (void *)(_lld_scan_sync_env + 4);
        iVar3 = memcmp(auStack_38,pvVar4,6);
        if (iVar3 != 0) {
          return 0;
        }
        if (*(byte *)(iVar2 + 2) != param_6) {
          return 0;
        }
        memcpy(pvVar4,&uStack_48,6);
        *(undefined1 *)(iVar2 + 3) = 1;
        return 1;
      }
    }
    iVar2 = _lld_scan_sync_env;
    uVar1 = 0;
    if ((*(byte *)(_lld_scan_sync_env + 3) == param_3) &&
       (iVar3 = memcmp(&uStack_48,(void *)(_lld_scan_sync_env + 4),6), iVar3 == 0)) {
      uVar1 = (uint)(*(byte *)(iVar2 + 2) == param_6);
    }
  }
  return uVar1;
}

