/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_adv_reports_list_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_llm_adv_reports_list_check
               (void *param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  byte *pbVar1;
  void *pvVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  
  if ((*(int *)(_p_llm_env + 0xcc) != 0) && (*(char *)(_p_llm_env + 0xd0) != '\0')) {
    iVar6 = 0;
    while( true ) {
      if ((int)(uint)*(byte *)(_p_llm_env + 0xd2) <= iVar6) break;
      uVar3 = r_co_bdaddr_compare(param_1,*(int *)(_p_llm_env + 0xcc) + iVar6 * 0xe);
      if ((((uVar3 != 0) &&
           (iVar5 = *(int *)(_p_llm_env + 0xcc) + iVar6 * 0xe, *(byte *)(iVar5 + 0xb) == param_2))
          && (*(byte *)(iVar5 + 10) == param_3)) && (*(byte *)(iVar5 + 0xc) == param_4)) {
        if ((param_4 == 0xff) || (*(ushort *)(iVar5 + 6) == param_5)) {
          if (param_6 < 6) {
            return uVar3;
          }
          uVar3 = 0;
        }
        else {
          *(short *)(iVar5 + 6) = (short)param_5;
          if (param_6 < 6) {
            return 0;
          }
        }
        if (*(ushort *)(iVar5 + 8) != param_6) {
          *(short *)(iVar5 + 8) = (short)param_6;
          return 0;
        }
        return (uVar3 ^ 1) & 0xff;
      }
      iVar6 = iVar6 + 1;
    }
    pvVar2 = memcpy((void *)(*(int *)(_p_llm_env + 0xcc) + (uint)*(byte *)(_p_llm_env + 0xd1) * 0xe)
                    ,param_1,6);
    iVar6 = _p_llm_env;
    *(char *)((int)pvVar2 + 10) = (char)param_3;
    *(char *)((int)pvVar2 + 0xb) = (char)param_2;
    *(char *)((int)pvVar2 + 0xc) = (char)param_4;
    *(short *)((int)pvVar2 + 6) = (short)param_5;
    *(short *)((int)pvVar2 + 8) = (short)param_6;
    r_ble_log_internal_x2
              (0x20c101f1,param_6 << 0x10 | param_5,
               (uint)*(byte *)(iVar6 + 0xd1) | param_4 << 0x18 | param_3 << 8 | param_2 << 0x10);
    iVar6 = _p_llm_env;
    pbVar1 = (byte *)(_p_llm_env + 0xd0);
    bVar4 = *(char *)(_p_llm_env + 0xd1) + 1;
    if (bVar4 == *pbVar1) {
      bVar4 = 0;
    }
    *(byte *)(_p_llm_env + 0xd1) = bVar4;
    bVar4 = *(byte *)(iVar6 + 0xd2);
    if (bVar4 < *pbVar1) {
      *(byte *)(iVar6 + 0xd2) = bVar4 + 1;
    }
  }
  return 0;
}

