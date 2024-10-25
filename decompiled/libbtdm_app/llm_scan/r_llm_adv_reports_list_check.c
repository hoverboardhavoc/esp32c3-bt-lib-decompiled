/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_adv_reports_list_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_llm_adv_reports_list_check
               (void *param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  char cVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if ((*(int *)(_p_llm_env + 0xcc) != 0) && (*(char *)(_p_llm_env + 0xd0) != '\0')) {
    iVar5 = 0;
    while( true ) {
      if ((int)(uint)*(byte *)(_p_llm_env + 0xd2) <= iVar5) break;
      uVar3 = (*(code *)*_r_modules_funcs_p)
                        (param_1,*(int *)(_p_llm_env + 0xcc) + iVar5 * 0xe,
                         (code *)*_r_modules_funcs_p);
      if ((((uVar3 != 0) &&
           (iVar4 = *(int *)(_p_llm_env + 0xcc) + iVar5 * 0xe, *(byte *)(iVar4 + 0xb) == param_2))
          && (*(byte *)(iVar4 + 10) == param_3)) && (*(byte *)(iVar4 + 0xc) == param_4)) {
        if ((param_4 == 0xff) || (*(ushort *)(iVar4 + 6) == param_5)) {
          if (param_6 < 6) {
            return uVar3;
          }
          uVar3 = 0;
        }
        else {
          *(short *)(iVar4 + 6) = (short)param_5;
          if (param_6 < 6) {
            return 0;
          }
        }
        if (*(ushort *)(iVar4 + 8) != param_6) {
          *(short *)(iVar4 + 8) = (short)param_6;
          return 0;
        }
        return (uVar3 ^ 1) & 0xff;
      }
      iVar5 = iVar5 + 1;
    }
    pvVar2 = memcpy((void *)(*(int *)(_p_llm_env + 0xcc) + (uint)*(byte *)(_p_llm_env + 0xd1) * 0xe)
                    ,param_1,6);
    iVar5 = _p_llm_env;
    *(char *)((int)pvVar2 + 10) = (char)param_3;
    *(char *)((int)pvVar2 + 0xb) = (char)param_2;
    *(char *)((int)pvVar2 + 0xc) = (char)param_4;
    *(short *)((int)pvVar2 + 6) = (short)param_5;
    *(short *)((int)pvVar2 + 8) = (short)param_6;
    cVar1 = *(char *)(iVar5 + 0xd1);
    *(char *)(iVar5 + 0xd1) = cVar1 + '\x01';
    if ((byte)(cVar1 + 1U) == *(byte *)(iVar5 + 0xd0)) {
      *(undefined1 *)(iVar5 + 0xd1) = 0;
    }
    if (*(byte *)(iVar5 + 0xd2) < *(byte *)(iVar5 + 0xd0)) {
      *(byte *)(iVar5 + 0xd2) = *(byte *)(iVar5 + 0xd2) + 1;
    }
  }
  return 0;
}

